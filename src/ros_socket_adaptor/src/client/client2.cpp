/**
 * @file client2.cpp
 * @author elliot (sun1f@foxmail.com)
 * @brief 每次向服务器端发送当前的全部位置坐标
 * @version 0.1
 * @date 2023-10-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("/home/sun/ros_socket_adaptor/src/ros_socket_adaptor/data/traj_example.txt");
    string query;
    vector<string> traj;
    vector<vector<float>> data_to_send;

    // 一次性读取文件中全部数据至traj
    while (getline(in, query))
    {
        traj.push_back(query);
    }

    while (1)
    {
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd == -1)
        {
            cout << "socket 创建失败：" << endl;
            exit(-1);
        }

        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(8888);
        addr.sin_addr.s_addr = inet_addr("10.134.115.5");

        int res = connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr));
        if (res == -1)
        {
            cout << "客户端连接失败：" << endl;
            exit(-1);
        }
        cout << "客户端连接成功：" << endl;

        data_to_send.clear();

        for (string s : traj)
        {
            string tmp;
            float x, y, z;
            int times = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] != ' ')
                {
                    tmp.push_back(s[i]);
                }
                else
                {
                    if (times == 1)
                    {
                        x = stof(tmp);
                    }
                    else if (times == 2)
                    {
                        y = stof(tmp);
                    }
                    else if (times == 3)
                    {
                        z = stof(tmp);
                    }
                    tmp.clear();
                    times++;
                }
            }
            data_to_send.push_back({x, y, z});
        }

        uint32_t size = data_to_send.size() * 3;
        cout << "actual data size = " << size << endl;
        send(socket_fd, (char *)&size, sizeof(uint32_t), 0);

        float buffer[size] = {0}; // 准备buffer的数据，实际发送的是buffer数组

        int count = 0;
        for (auto &x : data_to_send)
        {
            for (auto &f : x)
            {
                buffer[count++] = f;
            }
        }

        send(socket_fd, (char *)buffer, sizeof(buffer), 0);

        close(socket_fd);
        usleep(100000);
    }
    return 0;
}