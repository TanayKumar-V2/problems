#include<iostream>
using namespace std;

bool isArraySorted(int *a, int n){
    if(n==1 || n==0){
        return true;
    }
    if(a[0]<a[1] && isArraySorted(a+1, n-1)==true){
        return true;
    }
    return false;
}

bool isArraySorted3(int *a, int n, int i){
    if(i==n-1 || i==n){
        return true;
    }
    if(a[i]<a[i+1] && isArraySorted3(a, n, i+1)==true){
        return true;
    }
    return false;
}

int main(){

    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(int);

    if(isArraySorted(a,n)==true){
        cout<<"Sorted"<<endl;
    }
    if(isArraySorted3(a,n,0)==true){
        cout<<"Sorted"<<endl;
    }
    else{
        cout<<"Not sorted";
    }

    return 0;
}