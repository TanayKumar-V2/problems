#include<iostream>
using namespace std;

void bubbleSort(int *a, int n, int i){

    if(i==n-1 ){
        return;
    }

    for(int j=0;j<n-1;j++){
        if(a[j]>a[j+1]){
            swap(a[j], a[j+1]);
        }
    }
    bubbleSort(a,n,i+1);
}

int main(){
    int a[]={1,2,4,5,3};
    int n=sizeof(a)/sizeof(int);

    bubbleSort(a,n,0);
    return 0;
}