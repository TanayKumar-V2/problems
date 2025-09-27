#include<iostream>
using namespace std;

void subsequence(char *ip, int i, char*op,int  j){
    if(ip[i]=='\0'){
        op[j]='\0';
        cout<<op<<endl;
        return;
    }
    subsequence(ip, i+1,op, j);
    op[j]=ip[i];
    subsequence(ip, i+1,op,j+1);
}

int main(){
    char a[]="a";
    char op[100];
    subsequence(a,0,op,0);

    return 0;
}