#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string &str){
    stack<char>s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        switch(ch){
            case'(':
            case'{':
            case'[':
                s.push(ch);
                break;
            case')':
                if(!s.empty() and s.top()=='(') s.pop();
                else return false;
                break;
            case']':
                if(!s.empty() and s.top()=='[') s.pop();
                else return false;
                break;
            case'}':
                if(!s.empty() and s.top()=='{')s.pop();
                else return false;
                break;
        }
    }
    
    if(s.empty()) return true;
    else return false;
}

int main(){
    string s="{a+[b+(c+d)]+(e+f)}";
    if(isBalanced(s)){
        cout<<"It is Balanced";
    }else{
        cout<<"Not Balanced";
    }

    return 0;
}