#include<iostream>
#include<cmath>
using namespace std;

int solve(int x, int n){
    if(n==0){
        return 1;
    }
    return x*solve(x,n-1);
}

int main(){
    int x=3;
    int n=2;
    cout<<solve(x,n);

    return 0;
}