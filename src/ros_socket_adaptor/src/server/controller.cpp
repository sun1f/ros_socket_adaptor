#include "ros/ros.h"
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{

    ros::init(argc, argv, "controller");

    ros::NodeHandle n;

    ros::Publisher controller = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

    ros::Rate loop_rate(1);

    // 1.创建一个socket

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        cout << "socket 创建失败： " << endl;
        exit(1);
    }
    // 2.准备通讯地址（必须是服务器的）
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);                   // 将一个无符号短整型的主机数值转换为网络字节顺序，即大尾顺序(big-endian)
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // net_addr方法可以转化字符串，主要用来将一个十进制的数转化为二进制的数，用途多于ipv4的IP转化。
    // 3.bind()绑定

    int res = bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));

    vector<geometry_msgs::Point> vp;
    while (ros::ok())
    {
        if (res == -1)
        {
            // cout << "bind创建失败： " << endl;
            // exit(-1);
        }
        cout << "bind ok 等待客户端的连接" << endl;
        // 4.监听客户端listen()函数
        listen(socket_fd, 30);
        // 5.等待客户端的连接accept()，返回用于交互的socket描述符
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        int fd = accept(socket_fd, (struct sockaddr *)&client, &len);
        if (fd == -1)
        {
            cout << "accept错误\n"
                 << endl;
            exit(-1);
        }
        // 6.使用第5步返回socket描述符，进行读写通信。
        char *ip = inet_ntoa(client.sin_addr);
        cout << "客户： [" << ip << "]连接成功" << endl;

        float buffer[4] = {0};
        recv(fd, (char *)buffer, sizeof(buffer), 0);
        // int size = read(fd, buffer, sizeof(buffer));//通过fd与客户端联系在一起,返回接收到的字节数

        ROS_INFO("%f %f %f %f", buffer[0], buffer[1], buffer[2], buffer[3]);

        visualization_msgs::Marker points, line_strip;
        points.header.frame_id = line_strip.header.frame_id = "map";
        points.header.stamp = line_strip.header.stamp = ros::Time::now();
        points.ns = line_strip.ns = "points_and_lines";
        points.action = line_strip.action = visualization_msgs::Marker::ADD;
        points.pose.orientation.w = line_strip.pose.orientation.w = 1.0;

        points.id = 0;
        line_strip.id = 1;

        points.type = visualization_msgs::Marker::POINTS;
        line_strip.type = visualization_msgs::Marker::LINE_STRIP;

        // POINTS markers use x and y scale for width/height respectively
        points.scale.x = 0.1;
        points.scale.y = 0.1;

        // LINE_STRIP markers use only the x component of scale, for the line width
        line_strip.scale.x = 0.1;

        // Points are green
        points.color.g = 1.0f;
        points.color.a = 1.0;

        // Line strip is blue
        line_strip.color.b = 1.0;
        line_strip.color.a = 1.0;

        geometry_msgs::Point p;
        p.x = buffer[0];
        p.y = buffer[1];
        p.z = buffer[2];

        vp.push_back(p);

        for (auto &x : vp)
        {
            points.points.push_back(x);
            line_strip.points.push_back(x);
        }

        // controller.publish(points);
        controller.publish(line_strip);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}
