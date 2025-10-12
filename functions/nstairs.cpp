#include<iostream>
using namespace std;

int nStairs(int n, int k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans=0;
    for(int i=0;i<=k;i++){
        ans+=nStairs(n-1,k);
    }
}

int main(){
    int n,k=3;
    cin>>n;
    cout<<nStairs(n,k)<<endl;
    return 0;
}