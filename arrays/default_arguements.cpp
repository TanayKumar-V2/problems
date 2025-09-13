#include<iostream>
using namespace std;

int add(int a, int b, int c){
    return a+b+c;
}

int defAdd(int a, int b, int c=0){
    return a+b+c;
}

int main(){
    cout<<add(1,2,3)<<endl;
    cout<<defAdd(1,2)<<endl;

    return 0;
}