#include<iostream>
using namespace std;

void update(int &x){
    x=x+1;
}

int main(){
    int a=1;
    cout<<a<<endl;
    update(a);
    cout<<a<<endl;
}