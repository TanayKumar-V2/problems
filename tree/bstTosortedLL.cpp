#include <iostream>
#include <vector>
using namespace std;

// Simple BST node
struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val <= root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Singly linked list node for the sorted list
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int d) : data(d), next(nullptr) {}
};

// Helper: in-order traversal that appends nodes to the linked list
void bstToSortedList(Node* root, ListNode*& head, ListNode*& tail) {
    if (!root) return;
    bstToSortedList(root->left, head, tail);

    ListNode* ln = new ListNode(root->data);
    if (!head) {
        head = tail = ln;
    } else {
        tail->next = ln;
        tail = ln;
    }

    bstToSortedList(root->right, head, tail);
}

ListNode* convertBSTToSortedList(Node* root) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    bstToSortedList(root, head, tail);
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Build a sample BST
    Node* root = nullptr;
    vector<int> vals = {8, 10, 1, 6, 4, 7, 3, 14, 13};
    for (int v : vals) root = insert(root, v);

    // Convert to sorted linked list
    ListNode* head = convertBSTToSortedList(root);

    cout << "Sorted linked list: ";
    printList(head);

    return 0;
}
#include <iostream>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
node *insertInBST(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    if (root->data > data)
    {
        root->left = insertInBST(root->left, data);
        return root;
    }
    else
    {
        root->right = insertInBST(root->right, data);
        return root;
    }
}

node *buildBST()
{
    node *root = NULL;

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBST(root, data);

        cin >> data;
    }

    return root;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *f = q.front();
        q.pop();

        if (f != NULL)
        {
            // 1. Print the data
            cout << f->data << " ";

            if (f->left != NULL)
            {
                q.push(f->left);
            }

            if (f->right != NULL)
            {
                q.push(f->right);
            }
        }
        else
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

void printRange(node *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    printRange(root->left, k1, k2);
    if (root->data >= k1 and root->data <= k2)
    {
        cout << root->data << " ";
    }
    printRange(root->right, k1, k2);
}

class Pair
{
public:
    bool isBalanced;
    int height;
};

Pair isBSTbalanced(node *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.isBalanced = true;
        ans.height = 0;
        return ans;
    }
    Pair left = isBSTbalanced(root->left);
    Pair right = isBSTbalanced(root->right);
    Pair ans;
    if (left.isBalanced == true and right.isBalanced == true and abs(left.height - right.height) <= 1)
    {
        ans.isBalanced = true;
    }
    else
    {
        ans.isBalanced = false;
    }
    ans.height = max(left.height, right.height) + 1;
    return ans;
}

class LinkedList{
public:
    node*head,*tail;
};

LinkedList bstToLL(node*root){
    LinkedList l;
    if(root==NULL){
        l.head=l.tail=NULL;
        return l;
    }

    if(root->left!=NULL and root->right!=NULL){
        LinkedList left=bstToLL(root->left);
        LinkedList right=bstToLL(root->right);

        left.tail->right=root;
        root->right=right.head;

        l.head=left.head;
        l.tail=right.tail;
        return l;
    }
    else if(root->left!=NULL and root->right==NULL){
        LinkedList left=bstToLL(root->left);

        left.tail->right=root;
        l.head=left.head;
        l.tail=root;
        return l;
    }
    else if(root->left==NULL and root->right!=NULL){
        LinkedList right=bstToLL(root->right);
        root->right=right.head;
        l.head=root;
        l.tail=right.tail;
        return l;
    }
    else{
        l.head=l.tail=root;
        return l;
    }
}

int main()
{
    // 8 3 10 1 6 14 4 7 13 -1
    node *root = buildBST();
    inorder(root);
    cout << endl;
    LinkedList ans=bstToLL(root);
    node*head=ans.head;

    while(head!=NULL){
        cout<<head->data<<" --> ";
        head=head->right;
    }
    cout<<"NULL"<<endl;

    return 0;
}