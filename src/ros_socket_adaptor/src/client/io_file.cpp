/**
 * @file io_file.cpp
 * @author elliot (sun1f@foxmail.com)
 * @brief 数据格式转换：MH01.txt->traj_example.txt
 * @version 0.1
 * @date 2023-10-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string input_filename = "/home/sun/ros_socket_adaptor/src/ros_socket_adaptor/data/MH01.txt";
    string out_filename = "/home/sun/ros_socket_adaptor/src/ros_socket_adaptor/data/traj_example.txt";
    string query;
    ifstream in(input_filename);
    ofstream out(out_filename);
    while (getline(in, query))
    {
        string tmp;
        int count = 0;
        for (char c : query)
        {
            if (c != ' ' && count >= 1 && count < 4)
            {
                tmp += c;
            }
            else if (c == ' ')
            {
                tmp += ' ';
                count++;
            }
            else if (count == 4)
                break;
        }
        out << tmp << endl;
    }

    return 0;
}