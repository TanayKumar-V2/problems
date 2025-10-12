#include<iostream>
using namespace std;

bool ratInMaze(char maze[][6], int i, int j,int n, int m, int sol[][10]){
    if(i==n-1 && j==m-1){
        sol[i][j]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
            sol[i][j]=0;
            return false;
        }
        return true;
    }
    sol[i][j]=1;
    if(j+1<m and maze[i][j+1]!='X' and sol[i][j+1]!=1){
        bool isRight=ratInMaze(maze, i, j+1,n,m,sol);
        if(isRight){
            return true;
        }
    }
    if(i+1<n and maze[i+1][j]!='X' and sol[i+1][j]!=1){
        bool isDown=ratInMaze(maze, i+1,j,n,m,sol);
        if(isDown){
            return true;
        }
    }
    if(j-1>=0 and maze[i][j-1]!='X' and sol[i][j-1]!=1){
        bool isLeft=ratInMaze(maze, i,j-1,n,m,sol);
        if(isLeft){
            return true;
        }
    }

    if(i-1>=0 and maze[i-1][j]!='X' and sol[i-1][j]!=1){
        bool isUp=ratInMaze(maze,i-1,j,n,m,sol);
        if(isUp){
            return true;
        }
    }
    sol[i][j]=0;
    return false;
}

int main(){
    char maze[][6]={
        "0X000",
        "0X000",
        "00000",
        "0X000",
        "0X000",
    };

    int sol[10][10]={0};
    ratInMaze(maze,0,0,5,5,sol);

    return 0;
}