#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

template <typename T, typename InputIterator, typename OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
    vector<T> s;
    for (; first != last; ++first)
    {
        s.push_back(*first);
    }
    sort(s.begin(), s.end());
    copy(s.begin(), s.end(), result);
}

int main()
{
    double a[5] = {1.2, 2.4, 0.8, 3.3, 3.2};
    mySort<double>(a, a + 5, ostream_iterator<double>(cout, " "));
    cout << endl;

    return 0;
}