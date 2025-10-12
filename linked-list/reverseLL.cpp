#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

int lengthLL(node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        ans++;
        head = head->next;
    }
    return ans;
}

void insertAtEnd(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        head = tail = new node(data);
    }
    else
    {
        node *n = new node(data);
        tail->next = n;
        tail = n;
    }
}
void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void reverseLL(node *&head, node *&tail)
{
    node *c = head;
    node *p = NULL;

    while (c != NULL)
    {
        node *n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    swap(head, tail);
}

void reverseLLRecHelper(node*c, node*p=NULL){
    if(c==NULL){
        return ;
    }
    node*n=c->next;
    c->next=p;
    reverseLLRecHelper(n,c);
}

void reverseLLRec(node* &head, node* &tail){
    reverseLLRecHelper(head);
    swap(head,tail);
}

void deleteAtFront(node* &head, node* &tail){
    if(head==NULL){
        return ;
    }else if(head->next==NULL){
        delete head;
        head=tail=NULL;
    }else{
        
    }
}

int main()
{
    node *head, *tail;
    head = tail = NULL;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 4);
    cout << "Before Reversal: ";
    printLL(head);
    reverseLL(head, tail);
    cout << "After Reversal: ";
    printLL(head);
    reverseLLRec(head,tail);
    cout<<"Reversal Using Recursion: ";
    printLL(head);
    return 0;
}