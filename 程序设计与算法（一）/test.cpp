#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char *p;
    char str[] = "- this,a simple string.Ok";
    cout << str << endl;

    p = strtok(str, " -,.");
    while (p != NULL)
    {
        cout << p << endl;
        p = strtok(NULL, " -,.");
    }

    return 0;
}

