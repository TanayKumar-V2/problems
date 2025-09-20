#include<iostream>
using namespace std;

int printDecreasing(int n){

    if(n==0){
        return 0;
    }
    cout<<n<<endl;
    printDecreasing(n-1);
}

int printIncreasing(int n){
    if(n==0){
        return 0;
    }
    printIncreasing(n-1);
    cout<<n<<endl;
}

int main(){
    printDecreasing(4);
    printIncreasing(4);
    return 0;
}