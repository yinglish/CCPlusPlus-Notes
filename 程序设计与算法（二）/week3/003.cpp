#include <iostream>

using namespace std;

int placeApple(int apples, int plates)
{
    if (plates <= 0)
    {
        return 0;
    }

    if (apples == 0)
    {
        return 1;
    }

    if (plates > apples)
    {
        return placeApple(apples, apples);
    }
    else
    {
        return placeApple(apples - plates, plates) + placeApple(apples, plates - 1);
    }
    
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int apples, plates;
        cin >> apples >> plates;
        cout << placeApple(apples, plates) << endl;
    }
    return 0;
}