#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> a({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    // auto address = upper_bound(a.begin(), a.end(), 6);
    auto address = lower_bound(a.begin(), a.end(), 6);
    int pos = address - a.begin();
    if (address != a.end())
    {
        cout << "Index:" << pos << endl;
    }

    return 0;
}