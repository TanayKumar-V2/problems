#include<iostream>
using namespace std;


void pairSum(int a[], int sum, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==sum){
                cout<<a[i]<<" , "<<a[j]<<endl;
            }
        }
    }
}

int main(){
    int a[]={1,0,2,4,5,3};
    int n=sizeof(a)/sizeof(int);
    int sum=5;
    pairSum(a, sum, n);
    return 0;
}