#include<iostream>
using namespace std;

void spiralPrint(int a[][100], int n, int m){
    int sr=0,sc=0,er=n-1,ec=m-1;
    while(sr<=er and sr<=ec){
        for(int c=sc;c<=ec;++c){
            cout<<a[sr][c]<<" ";
        }
        sr++;
        for(int r=sr;r<=er;++r){
            cout<<a[r][ec]<<" ";
        }
        ec--;
        if(sr<er){
            for(int c=ec;c>=sc;--c){
                cout<<a[er][c]<<" ";
            }
        }
        if(sc<ec){
            for(int r=er;r>=sr;--r){
                cout<<a[r][sc]<<" ";
            }
            sc++;
        }
    }
}

int main(){
    int a[100][100];
    int num=1;
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            a[i][j]=num;
            num++;
        }
    }
    spiralPrint(a,r,c);
    return 0;
}