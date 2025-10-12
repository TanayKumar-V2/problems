#include<iostream>
using namespace std;

char key[][10]={
    "","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WZYZ"
};

void phoneKeyPad(char *ip, char *op,int i, int j ){
    if(ip[i]=='\0'){
        op[j]='\0';
        cout<<op<<endl;
        return;
    }

    int digit=ip[i]-'0';
    for(int k=0;key[digit][k]!='\0';k++){
        op[i]=key[digit][k];
        phoneKeyPad(ip,op,i+1,j+1);
    }
}

int main(){
    char a[1000];
    cin>>a;
    char op[100];
    phoneKeyPad(a,op,0,0);
    return 0;

}