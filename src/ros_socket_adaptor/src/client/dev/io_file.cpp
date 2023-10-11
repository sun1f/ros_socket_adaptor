#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string input_filename = "MH01.txt";
    string out_filename = "traj_example.txt";
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