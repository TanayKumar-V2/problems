#include<iostream>
using namespace std;

void print(char ch, char a[]){
    int i=0;

    while(ch!='\n'){
        a[i]=ch;
        i++;

        ch=cin.get();
    }
    a[i]='\0';
    cout<<a<<endl;
}

int main(){
    char a[100];
    char ch;
    ch=cin.get();

    // ch=cin.get();

    // int i=0;

    // while(ch!='\n'){
    //     a[i]=ch;
    //     i++;

    //     ch=cin.get();
    // }

    // a[i]='\0';

    print(ch, a);


    return 0;
}