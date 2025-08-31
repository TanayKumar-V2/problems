#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    while (i < 5)
    {
        cout << i;
        if (i == 3)
        {
            continue;
        }
        i++;
    }
}