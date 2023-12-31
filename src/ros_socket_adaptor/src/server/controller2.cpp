/**
 * @file controller2.cpp
 * @author elliot (sun1f@foxmail.com)
 * @brief 一次发送所有位置坐标
 * @version 0.1
 * @date 2023-10-13
 *
 * @copyright Copyright (c) 2023
 *
 */
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
    addr.sin_port = htons(8888);                      // 将一个无符号短整型的主机数值转换为网络字节顺序，即大尾顺序(big-endian)
    addr.sin_addr.s_addr = inet_addr("10.134.115.5"); // net_addr方法可以转化字符串，主要用来将一个十进制的数转化为二进制的数，用途多于ipv4的IP转化。
    // 3.bind()绑定

    int res = bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));

    vector<geometry_msgs::Point> vp; // 每次循环需要绘制的所有点

    while (ros::ok())
    {
        if (res == -1)
        {
            cout << "bind创建失败：" << endl;
            exit(-1);
        }
        cout << "bind ok 等待客户端的连接..." << endl;
        // 4.监听客户端listen()函数
        listen(socket_fd, 30);
        // 5.等待客户端的连接accept()，返回用于交互的socket描述符
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        int fd = accept(socket_fd, (struct sockaddr *)&client, &len);
        if (fd == -1)
        {
            cout << "accept错误" << endl;
            exit(-1);
        }
        // 6.使用第5步返回socket描述符，进行读写通信。
        char *ip = inet_ntoa(client.sin_addr);
        cout << "客户： [" << ip << "]连接成功" << endl;

        vp.clear();

        uint32_t size = 0;
        recv(fd, (char *)&size, sizeof(uint32_t), 0);
        cout << "size = " << size << endl;

        float buffer[size] = {0};
        recv(fd, (char *)buffer, sizeof(buffer), 0);
        // cout << "buffer[3] = " << buffer[3] << endl;

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

        for (int i = 0; i + 3 < size; i += 3)
        {
            geometry_msgs::Point p;
            p.x = buffer[i];
            p.y = buffer[i + 1];
            p.z = buffer[i + 2];
            vp.push_back(p);
        }
        // cout << "still ok1" << endl;

        for (auto &x : vp)
        {
            points.points.push_back(x);
            line_strip.points.push_back(x);
        }
        // cout << "still ok2" << endl;

        // controller.publish(points);
        controller.publish(line_strip);
        // cout << "still ok3" << endl;

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}
