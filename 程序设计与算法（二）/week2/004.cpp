#include <iostream>
#include <cstdlib>

using namespace std;

double exp()
{
    char ex[20];
    cin >> ex;
        
    switch (ex[0])  
    {
        
        case '+': return exp() + exp();
        
        case '-': return exp() - exp();
        
        case '*': return exp() * exp();
        
        case '/': return exp() / exp();

        default: return atof(ex);
        
    }

}

int main()
{
    cout << exp() << endl;
    return 0;
}