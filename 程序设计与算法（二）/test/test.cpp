#include <iostream>

using namespace std;

const int NUM = 300;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void primeNormal()
{
    for (int i = 2; i <= NUM; ++i)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void primeSelect()
{
    bool prime[NUM + 1];
    for (int i = 0; i < NUM + 1; ++i)
    {
        prime[i] = true;
    }

    for (int i = 2; i * i <= NUM; ++i)
    {
        for (int j = i + 1; j <= NUM; ++j)
        {
            if (j % i == 0)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= NUM; ++i)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main()
{
    primeNormal();
    primeSelect();
}