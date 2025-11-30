#include <iostream>
#include <queue>
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

node *createTree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    node *root = new node(data);
    root->left = createTree();
    root->right = createTree();
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
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
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

int countNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lstNodesCount = countNodes(root->left);
    int rstNodesCount = countNodes(root->right);

    return 1 + lstNodesCount + rstNodesCount;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lstHeight = height(root->left);
    int rstHeight = height(root->right);

    int ans = max(lstHeight, rstHeight) + 1;
    return ans;
}

int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lstHeight = height(root->left);
    int rstHeight = height(root->right);
    int op1 = lstHeight + rstHeight;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}

class Pair
{
public:
    int height, diameter;
};

Pair fastDiameter(node *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.height = ans.diameter = 0;
        return ans;
    }

    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);
    Pair ans;
    ans.height = max(left.height, right.height) + 1;
    int op1 = left.height + right.height;
    int op2 = left.diameter;
    int op3 = right.diameter;
    ans.diameter = max(op1, max(op2, op3));
    return ans;
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

void mirrorTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main()
{
    node *root = createTree();
    cout << "Pre-Order: " << endl;
    preorder(root);
    cout << "In-Order: " << endl;
    inorder(root);
    cout << "Post-Order: " << endl;
    postorder(root);
    cout << "Nodes Count: " << countNodes(root) << endl;
    cout << "Height of the tree: " << height(root) << endl;
    cout << "Diamater: " << diameter(root) << endl;
    Pair ans = fastDiameter(root);
    cout << "fast height: " << ans.height << endl;
    cout << "fast diameter: " << ans.diameter << endl;
    levelOrderTraversal(root);
    mirrorTree(root);
    levelOrderTraversal(root);
    return 0;
}
