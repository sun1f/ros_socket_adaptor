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
    ifstream in("utils/traj_example.txt");
    string query;
    vector<string> traj;
    while (getline(in, query))
    {
        traj.push_back(query);
    }

    int size = traj.size(), count = 0;

    while (count < size)
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
            cout << "bind 链接失败：" << endl;
            exit(-1);
        }
        cout << "bind 链接成功：" << endl;

        string s = traj[count++];
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

        float a[4] = {x, y, z, 1.0};
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
        send(socket_fd, (char *)a, sizeof(a), 0);
        close(socket_fd);
        sleep(1);
    }

    return 0;
}
