/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement AVL tree.
*********************************************************************/

#include <iostream>
#include <queue>

using namespace std;

typedef struct node {
	int data;
	int height;
	struct node* left;
	struct node* right;
}node;

int max(int a, int b) {
	return a > b ? a : b;
}//End max

node* createNode(int data) {
	node *nn = new node();
	nn->data = data;
	nn->height = 0;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}//End createNode

int height(node *root) {
	if(root==NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}//End height

int getBalance(node *root) {
	return height(root->left) - height(root->right);
}//End getBalance

node* rightRotate(node *root) {
	node *t = root->left;
	node *u = t->right;
	t->right = root;
	root->left = u;
	return t;
}//End rightRotate

node* leftRotate(node *root) {
	node *t = root->right;
	node *u = t->left;
	t->left = root;
	root->right = u;
	return t;
}//End leftRotate

node* minValue(node* root) {
	if(root->left==NULL)
		return root;
	return minValue(root->left);
}//End minValue

node* insert(node* root, int item) {
	node *nn = createNode(item);
	if(root == NULL)
		return nn;
	if(item<root->data)
		root->left = insert(root->left, item);
	else
		root->right = insert(root->right, item);
	
	int b = getBalance(root);
	
	if(b>1) {
		if(getBalance(root->left)<0)
			root->left = leftRotate(root->left);  // Left-Right Case
		return rightRotate(root);				  // Left-Left Case	
	}
	 else if(b<-1) 
	{
		if(getBalance(root->right)>0)
			root->right = rightRotate(root->right);  // Right-Left Case
		return leftRotate(root);				    // Right-Right Case
	}//End if

	return root;
}//End insert

node* deleteNode(node *root, int key) {
	if(root == NULL)
		return root;
	if(key < root->data)
		root->left = deleteNode(root->left, key);
	else if(key >  root->data)
		root->right = deleteNode(root->right, key);

	 else 
	{
		if(!root->right) {
			node* temp = root->left;
			delete(root);
			root = NULL;
			return temp;
		}
		 else if(!root->left) 
		{
			node* temp = root->right;
			delete(root);
			root = NULL;
			return temp;
		}//End if

		node *temp = minValue(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}//End if
	
	return root;
}//End deleteNode

void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		root = q.front();
		cout<<root->data<<" ";
		q.pop();
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}//End while
}//End levelOrder

int main() {
	cout<<endl;
	cout<<"AVL Tree"<<endl;
	cout<<"Please choose an option:"<<endl;

	node *root = NULL;
	int i;
	for(i = 1 ; i <= 7 ; i++)
		root = insert(root, i);
	
	cout<<"LevelOrder: "<<endl;
	levelOrder(root);
	root = deleteNode(root, 1); 
	
	cout<<"\nLevelOrder: "<<endl;
	levelOrder(root);
    root = deleteNode(root, 4); 
	
	cout<<"\nLevelOrder: "<<endl;
	levelOrder(root);
	
	return 0;
}//End main
