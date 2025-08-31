#include<iostream>
using namespace std;

int main(){
    int a[]={2,3,5,1,4};
    int n=sizeof(a)/sizeof(a[0]);

    for(int i=0;i<n-1;i++){
        int mi=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mi]){
                mi=j;
            }
        }
        swap(a[i],a[mi]);
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}