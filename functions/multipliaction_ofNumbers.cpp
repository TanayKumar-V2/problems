#include<iostream>
using namespace std;

int multiply(int a, int b){
    if(b==0){
        return 0;
    }
    return a+multiply(a,b-1);
}

int main(){
    cout<<multiply(1,3);
    return 0;
}

