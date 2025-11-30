#include<iostream>
#include<queue>
using namespace std;

class cmp{
public:
    bool operator()(int a , int b){
        return a>b;
    }
};

void printheap(priority_queue<int, vector<int>, cmp>h){
    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }
    cout<<endl;
}

int main(){
    priority_queue<int, vector<int>, cmp>h;
    int k=3;
    int cs=0;
    while(true){
        int data;
        cin>>data;

        if(data==-1){
            printheap(h);
        }else{
            if(cs==k){
                if(h.top()<data){
                    h.pop();
                    h.push(data);
                }
            }else{
                h.push(data);
                cs++;
            }
        }
    }
    return 0;
}