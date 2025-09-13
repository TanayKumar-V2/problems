#include<iostream>
using namespace std;

int main(){
    char a[100];
    cin.getline(a,100);

    int cnt = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        cnt++;
    }

    int i=0;
    int j=cnt-1;

    while(i<j){
        if(a[i]!=a[j]){
            cout<<"Not a palindrome";
            return 0;
        }
        i++;
        j--;
    }

    cout<<"Its a palindrome";
    return 0;
}