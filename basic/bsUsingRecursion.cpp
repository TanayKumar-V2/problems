#include<iostream>
using namespace std;

int binarySearch(int *a, int s, int e, int key){
    if(s>e) return -1;

    int m=s+(e-s)/2;

    if(a[m]==key){
        return m;
    }else if(key<a[m]){
        return binarySearch(a,s,m-1,key);
    }else{
        return binarySearch(a,m+1,e,key);
    }
}

int main(){
    int a[]={1,3,5,7,9};
    int n=sizeof(a)/sizeof(int);

    cout<<binarySearch(a,0,n-1,5);
    return 0;
}