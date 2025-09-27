#include<iostream>
using namespace std;

bool ifSevenisPresent(int *a, int n, int idx=0){
    if(idx==n){
        return false;
    }
    if(a[idx]==7) return true;
    return ifSevenisPresent(a,n,idx+1);
}

int firstIndex(int *a, int n,int idx=0){
    if(idx==n){
        return -1;
    }
    if(a[idx]==7) return idx;
    return firstIndex(a, n, idx+1);
}

int lastIndex(int *a, int n, int idx=0){
    if(idx==n){
        return -1;
    }
    int rest=lastIndex(a, n, idx+1);
    if(rest!=-1) return rest;
    if(a[idx]==7) return idx;
    return -1;
}

int main(){
    int a[]={1,2,7,4,7,8,9,7};
    int n=sizeof(a)/sizeof(int);

    cout << "Is 7 present? " << (ifSevenisPresent(a,n,0) ? "Yes" : "No") << endl;
    cout << "First index of 7: " << firstIndex(a,n,0) << endl;
    cout << "Last index of 7: " << lastIndex(a,n,0) << endl;

    return 0;
}