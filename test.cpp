#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string line = "1 2";
    string z = "";
    z += line[0];
    int a = stoi(z);
    cout << a << endl;

    // string fileName = "0.png";
    // ifstream file;
    // file.open(fileName);

    // if (!file.is_open())
    // {
    //     cout << "No have file" << endl;
    //     return 0;
    // }
    // else
    // {
    //     cout << "Have file" << endl;
    // }

    // string line;
    // for (int i = 0; i < 10; i++)
    // {
    //     getline(file, line);
    //     string elements[30];
    //     cout << line << endl;
    //     int index = 0;
    //     for (int j = 0; j < line.length(); j++)
    //     {
    //         if (line[j] == 32)
    //             continue;
    //         elements[index++] = line[j];
    //     }
    //     cout << elements[29] << endl;
    // }
    return 0;
}