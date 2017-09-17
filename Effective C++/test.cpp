#include <iostream>
#include <vector>

using namespace std;

class A
{
private:
    const static int a = 9;
    static int count;
    int scores[a];
public:
    void get_a() {cout << "a: " << a << endl;}
    void get_count() {cout << "count: " << count << endl;}
};
int A::count = 10;
int main()
{
    
    int a[] = {1, 2,3};
    vector<int> vec(a, a + 3);
    
    return 0;
}