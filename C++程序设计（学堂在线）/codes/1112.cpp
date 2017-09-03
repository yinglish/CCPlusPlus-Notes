#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
inline T FromString(const string &str)
{
    istringstream is(str);
    T v;
    is >> v;
    return v;
}

int main()
{
    int v1 = FromString<int>("5");
    cout << v1 << endl;
    double v2 = FromString<double>("1.2");
    cout << v2 << endl;
    return 0;
}