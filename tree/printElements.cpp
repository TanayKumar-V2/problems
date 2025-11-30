#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
node* insertInBST(node* root, int data) {
	if (root == NULL) {
		root = new node(data);
		return root;
	}

	if (root->data > data) {
		root->left = insertInBST(root->left, data);
		return root;
	}
	else {
		root -> right = insertInBST(root->right, data);
		return root;
	}
}

node* buildBST() {
	node* root = NULL;

	int data;
	cin >> data;

	while (data != -1) {
		root = insertInBST(root, data);

		cin >> data;
	}

	return root;
}

void preorder(node* root) {
	if (root == NULL) {
		return; 
	}

	cout << root->data << " "; 
	preorder(root->left);
	preorder(root->right); 
}

void inorder(node* root) {
	if (root == NULL) {
		return; 
	}

	inorder(root->left);
	cout << root->data << " "; 
	inorder(root->right); 
}

void postorder(node* root) {
	if (root == NULL) {
		return; 
	}

	postorder(root->left);
	postorder(root->right); 
	cout << root->data << " "; 
}

void levelOrderTraversal(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* f = q.front();
		q.pop();

		if (f != NULL) {
			// 1. Print the data
			cout << f->data << " ";

			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}

		}
		else { 
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		}
	}
}

void printRange(node*root, int k1,int k2){
    if(root==NULL){
        return;
    }
    printRange(root->left,k1,k2);
    if(root->data>=k1 and root->data<=k2){
        cout<<root->data<<" ";
    }
    printRange(root->right, k1,k2);
}


int main() {
	// 8 3 10 1 6 14 4 7 13 -1
	node*root=buildBST();
    inorder(root);
    cout<<endl;

    printRange(root,6,10);
	return 0;
}