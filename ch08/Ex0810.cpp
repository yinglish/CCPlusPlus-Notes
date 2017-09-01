#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input;
    input.open("new.txt");

    vector<string> strline;

    string temp;
    while (getline(input, temp))
    {
        strline.push_back(temp);
    }



    vector<string> strword;

    for (auto line : strline)
    {
        istringstream sinput;
        sinput.str(line);
        string temp1;
        while (sinput >> temp1)
        {
            strword.push_back(temp1);
        }
    }

    for (const auto a : strline)
    {
        cout << a << endl;
    }

    for (const auto b : strword)
    {
        cout << b << endl;
    }
}
