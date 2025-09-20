#include <iostream>
using namespace std;

int main()
{
    int a[3][3];
    int target;
    cout << "Enter Target: " << endl;
    cin >> target;
    int number = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = number;
            number++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == target)
            {
                cout << i << " , " << j << endl;
                break;
            }
        }
    }

    return 0;
}