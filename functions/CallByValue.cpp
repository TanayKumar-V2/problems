#include<iostream>
using namespace std;

//call by value concept

void update(int x){
    x=x+1;
}

//call by reference

void update1(int &x){
    x=x+1;
}

int main(){
    int a=1;
    cout<<"Before Update: "<<a<<endl;
    update(a);
    cout<<"After Update: "<<a<<endl;
    update1(a);
    cout<<"After Call by reference update: "<<a<<endl;
    return 0;
}