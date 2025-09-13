#include<iostream>
using namespace std;

int main(){
    int value = 0;
    int *a = &value;
    cout<<a<<endl;
    cout<<*a<<endl;
    return 0;
}