#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Invalid input. Number of elements must be positive." << endl;
    }
    int num, largest;
    cout << "Enter number 1: ";
    cin >> num;
    largest = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        if (num > largest)
        {
            largest = num;
        }
    }
    cout << "The largest number is: " << largest << endl;
    return 0;
}