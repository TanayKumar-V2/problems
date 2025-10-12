#include<iostream>
using namespace std;

bool isSafe(int board[][100], int j , int i, int n){
    for(int r=0;r<i;r++){
        if(board[r][j]==1){
            return false;
        }
    }

    int oi=i;
    int oj=j;

    while(i>=0 and j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    i=oi;
    j=oj;

    while(i>=0 and j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    return true;
}

bool nQueen(int board[][100], int row, int n){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout<<"Q";
                }else{
                    cout<<" _ ";
                }
            }
            cout<<endl;
        }
        return true;
    }
    for(int col=0;col<n;col++){
        if(isSafe(board, col,row,n)){
            board[row][col]=1;
            bool isPlaced=nQueen(board, row+1, n);
            if(isPlaced){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    int board[100][100]={0};
    int n;
    cin>>n;
    nQueen(board, 0,n);
    return 0;
}