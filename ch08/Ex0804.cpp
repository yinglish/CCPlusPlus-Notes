#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


void ReadFileContent(ifstream &in, string name, vector<string> &buf)
{
    in.open(name);

    string str;
    while (getline(in, str))
    {
        buf.push_back(str);
    }
}

int main()
{
    ifstream in;
    string name = "new.txt";
    vector<string> buf;
    ReadFileContent(in, name, buf);
    for (auto ele : buf)
    {
        cout << ele << endl;
    }

    return 0;
}
