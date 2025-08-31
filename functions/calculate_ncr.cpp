#include<iostream>
using namespace std;

int factorial(int n){
    int fact=1;
    for(int i=n;i>0;i--){
        fact*=i;
    }
    return fact;
}

int calculateNcr(int n, int r){
    int diff;
    diff=n-r;
    int final=factorial(n)/(factorial(r)*factorial(diff));
    return final;
}

int main(){
    int n, r; cin>>n>>r;
    int ans=calculateNcr(n,r);
    cout<<ans;
    return 0;
}