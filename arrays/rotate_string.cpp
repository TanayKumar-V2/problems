#include<iostream>
#include<cstring>
using namespace std;

void rotateString(char *a , int k){
    int len=strlen(a);
    int i=len-1;
    while(i>=0){
        a[i+k]=a[i];
        i--;
    }
    i=0;
    int j=len;
    while(i<k){
        a[i]=a[j];
        i++;
        j++;
    }
    a[len]='\0';
}

void reverseString(char *a, int i , int j){

 while(i<j){
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void rotateString1(char *a, int k){
    int len=strlen(a);
    k%=len;
    reverseString(a, 0, len-1);
    reverseString(a, 0, k-1);
    reverseString(a, k, len-1);
}

int main(){
    char a[100];
    int k;
    cin.getline(a, 100);
    cin>>k;

    rotateString1(a,k);

    cout<<a<<endl;

    return 0;
}