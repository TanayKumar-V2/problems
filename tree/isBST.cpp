#include <iostream>
#include <queue>
#include <climits>
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

class Tuple
{
public:
    bool isBST;
    int mi, mx;
};

Tuple isBST(node *root)
{
    if (root == NULL)
    {
        Tuple ans;
        ans.isBST = true;
        ans.mi = INT_MAX;
        ans.mx = INT_MIN;

        return ans;
    }
    Tuple left = isBST(root->left);
    Tuple right = isBST(root->right);

    Tuple ans;

    if (left.isBST == true and right.isBST and root->data > left.mx and root->data <= right.mi)
    {
        ans.isBST = true;
    }
    else
    {
        ans.isBST = false;
    }
    ans.mx = max(root->data, max(left.mx, right.mx));
    ans.mi = min(root->data, min(left.mi, right.mi));
}

bool kyaBSThai(node *root, int mi = INT_MIN, int mx = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= mi and root->data <= mx and kyaBSThai(root->left, mi, root->data) == true and kyaBSThai(root->right, root->data, mx) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // 8 3 10 1 6 14 4 7 13 -1
    node *root = buildBST();
    inorder(root);
    cout << endl;

    Tuple ans = isBST(root);
    if (ans.isBST)
    {
        cout << "It is BST"<<endl;
    }
    else
    {
        cout << "Not a BST"<<endl;
    }
    if (kyaBSThai)
    {
        cout << "Is BST" << endl;
    }
    else
    {
        cout << "Not a BST"<<endl;
    }
    return 0;
}