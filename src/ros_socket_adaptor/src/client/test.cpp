/**
 * @file test.cpp
 * @author elliot (sun1f@foxmail.com)
 * @brief 从traj_example.txt中按行读取数据
 * @version 0.1
 * @date 2023-10-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("/home/sun/ros_socket_adaptor/src/ros_socket_adaptor/data/traj_example.txt");
    vector<string> traj;
    string query;
    while (getline(in, query))
    {
        traj.push_back(query);
    }
    int count = 0, size = traj.size();
    cout << "size = " << size << endl;
    cout << traj[3] << endl;

    while (count < size)
    {
        int times = 0;

        string s = traj[count++];
        string tmp;
        float x, y, z;
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
                    cout << "times == 1, x = " << tmp << endl;
                    tmp.clear();
                }
                // x = stof(tmp);
                else if (times == 2)
                {
                    // y = stof(tmp);
                    cout << "times == 2, y = " << tmp << endl;

                    // z = stof(s.substr(i + 1, s.size() - i - 1));
                }
                else if (times == 3)
                {
                    cout << "times == 3, z = " << tmp << endl;
                }
                tmp.clear();
                times++;
            }
        }
    }

    /*  string s[3] = {"1.3232322", "-4.212312", "-9.09092"};
     float x = stof(s[0]);
     float y = stof(s[1]);
     float z = stof(s[2]);
     float a[4] = {x, y, z, 4.42};

     cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl; */

    return 0;
}