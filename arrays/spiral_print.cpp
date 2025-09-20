#include<iostream>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    int a[r][c];
    int num=1;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            a[i][j]=num;
            num++;
        }
    }

    
}