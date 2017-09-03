#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
inline string ToString(const T &v)
{
    ostringstream os;
    os << v;
    return os.str();
}

int main()
{
    string str1 = ToString(5);
    cout << str1 << endl;
    string str2 = ToString(1.2);
    cout << str2 << endl;
    return 0;
}