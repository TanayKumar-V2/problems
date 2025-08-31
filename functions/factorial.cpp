#include<iostream>
using namespace std;

int factorial(int n){
    int fact=1;
    for(int i=n;i>0;i--){
        fact*=i;
    }
    return fact;
}

int main(){
    int n; cin>>n;
    int f=factorial(n);
    cout<<f;
    return 0;
}