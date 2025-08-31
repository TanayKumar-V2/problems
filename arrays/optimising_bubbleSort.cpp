#include<iostream>
using namespace std;

int main(){
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);

    for(int i=0;i<n-1;i++){
        bool isSwap=false;

        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                isSwap=true;
                swap(a[j], a[j+1]);
            }
        }
        if(isSwap==false){
            break;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    return 0;
}