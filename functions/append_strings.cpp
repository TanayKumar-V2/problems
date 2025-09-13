#include <iostream>
using namespace std;

void append(char *a, char*b){
    int i=0;

    while(a[i]!='\0'){
        i++;
    }

    int j=0;

    while(b[j]!='\0'){
        a[i]=b[j];
        i++;
        j++;
    }
    a[i]='\0';

    cout<<a<<endl;
}

int main(){
    char a[100];
    char b[100];

    cin.getline(a, 100);
    cin.getline(b, 100);

    append(a,b);
    
    return 0;
}
