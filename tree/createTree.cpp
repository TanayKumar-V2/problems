#include <iostream>
#include<queue>
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

int pre[] = {8, 10, 1, 6, 4, 7, 3, 14, 13};
int k = 0;

node *createTree(int *in, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    node *root = new node(pre[k]);
    k++;

    int i = -1;
    for (int j = s; j <= e; j++)
    {
        if (in[j] == root->data)
        {
            i = j;
            break;
        }
    }

    if (i == -1)
    {
        cerr << "Error: value " << root->data << " not found in inorder array range [" << s << "," << e << "]\n";
        return root; 
    }

    root->left = createTree(in, s, i - 1);
    root->right = createTree(in, i + 1, e);
    return root;
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

node*searchtree(node*root, int key){

    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        return root;
    }
    node*leftAns=searchtree(root->left, key);
    if(leftAns!=NULL){
        return leftAns;
    }

    node*rightAns=searchtree(root->right, key);
    return rightAns;
}

int main(){
    int in[]={1,10,4,6,7,8,3,14,13};
    int n = sizeof(in) / sizeof(int);

    k = 0;

    node* root = createTree(in, 0, n-1);
    levelOrderTraversal(root);

    node *ans=searchtree(root,14);
    if(ans==NULL){
        cout<<"NOT FOUND";
    }else{
        cout<<ans->data<<" ";
    }
    cout<<endl;
    return 0;
}