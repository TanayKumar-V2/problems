#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int d){
        if(q1.empty()==true and q2.empty()==true){
            q1.push(d);
        }
        else if(q1.empty()==false){
            q1.push(d);
        }
        else{
            q2.push(d);
        }
    }
    void pop(){
        if(q1.empty()==false and q2.empty()==true){
            while(q1.size()>1){
                int f=q1.front();
            }
        }
    }
    int top(){
        if(q1.empty()==false and q2.empty()==true){
            while(q1.size()>1){
                int f=q1.front();
                q1.pop();
                q2.push(f);
            }
            int top=q1.front();
            q1.pop();
            q2.push(top);
            return top;
        }else{
           while(q2.size()>1){
                int f=q2.front();
                q2.pop();
                q1.push(f);
            }
            int top=q2.front();
            q2.pop();
            q1.push(top);
            return top; 
        }
    }

    bool empty(){
        if(q1.empty()==true and q2.empty()==true){
            return true;
        }else{
            return false;
        }
    }

};

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}