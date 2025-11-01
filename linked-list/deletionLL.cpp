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

void deleteAtFront(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node *t = head;
        head = head->next;
        delete t;
    }
}

void deletionAtEnd(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node *t = head;
        while (t->next != tail)
        {
            t = t->next;
        }
        delete tail;
        t->next = NULL;
        tail = t;
    }
}

void deleteAtMid(node *&head, node *&tail, int pos)
{
    if (pos == 0)
    {
        deleteAtFront(head, tail);
    }
    else if (pos >= lengthLL(head) - 1)
    {
        deletionAtEnd(head, tail);
    }
    else
    {
        node *t = head;
        for (int i = 0; i < pos - 1; i++)
        {
            t = t->next;
        }
        node *n = t->next;
        t->next = n->next;
        delete n;
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
    insertAtEnd(head, tail, 5);
    insertAtEnd(head, tail, 6);
    insertAtEnd(head, tail, 7);
    cout << "Before Deletion: ";
    printLL(head);
    deleteAtFront(head, tail);
    cout << "After Deletion: ";
    printLL(head);
    deletionAtEnd(head, tail);
    cout << "After deletion at end: ";
    printLL(head);
    deleteAtMid(head, tail, 3);
    cout << "After deleting 3rd pos: ";
    printLL(head);
    return 0;
}