#include <iostream>

using namespace std;

int divide(int x, int y)
{
    if (y == 0)
        throw x;
    return x / y;
}

int main()
{
    try{
        cout << "5 / 2" << divide(5, 2) << endl;
        cout << "8 / 0" << divide(8, 0) << endl;
        cout << "6 / 3" << divide(6, 3) << endl;
    }
    catch( int e)
    {
        cout << e << " cannot be divided by 0" << endl;
    }

    return 0;
}