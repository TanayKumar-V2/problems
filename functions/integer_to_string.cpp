#include <iostream>
using namespace std;

string digitWords[] = {"zero", "one", "two", "three", "four", 
                       "five", "six", "seven", "eight", "nine"};

void printDigits(int n) {
    if (n == 0)
        return;
    printDigits(n / 10);
    cout << digitWords[n % 10] << " ";
}

int main() {
    int number; cin>>number;
    
    printDigits(number);

    cout << endl;
    return 0;
}
