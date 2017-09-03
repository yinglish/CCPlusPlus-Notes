#include <iostream>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    istream_iterator<int> i1(cin), i2;
    vector<int> s1(i1, i2);
    sort(s1.begin(), s1.end());
    deque<int> s2;

    cout << "test1" << endl;
    for (vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter)
    {
        if (*iter % 2 == 0)
        {
            s2.push_back(*iter);
        }
        else
        {
            s2.push_front(*iter);
        }
    }
    cout << "test2" << endl;
    copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}