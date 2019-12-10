/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement tree.
*********************************************************************/

#include<iostream>
using namespace std;


struct node
{
	int val;
	node *left;
	node *right;
};//End struct node

struct queue
{
	node *t[100];
	int front;
	int rear;
};//End struct queue

queue q;

void enqueue(node *n)
{
	q.t[q.rear++]=n;
}//End enqueue

node * dequeue()
{
	return (q.t[q.front++]);
}//End dequeue

void CreateTree(node *curr, node *n, int x, char pos)
{
	if(n!=NULL)
	{
		char ch;
		cout<<"\nLeft or Right of "<<n->val<<" : "<<endl;
		cin>>ch;
		if(ch=='l')
			CreateTree(n, n->left, x, ch);
		else if(ch=='r')
			CreateTree(n, n->right, x, ch);
	}
	 else
	{
		node *t=new node;
		t->val=x;
		t->left=NULL;
		t->right=NULL;
		if (pos=='l')
		{
			curr->left=t;
		}
		 else if(pos=='r')
		{
			curr->right=t;
		}//End if
	}//End if
}//End CreateTree

void BFT(node *n)
{
	if(n!=NULL)
	{
		cout<<n->val<<"  "<<endl;
		enqueue(n->left);
		enqueue(n->right);
		BFT(dequeue());
	}//End if
}//End BFT

void Pre(node *n)
{
	if (n!=NULL)
	{
		cout<<n->val<<"  "<<endl;
		Pre(n->left);
		Pre(n->right);
	}//End if
}//End Pre

void In(node *n)
{
	if (n!=NULL)
	{
		In(n->left);
		cout<<n->val<<"  "<<endl;
		In(n->right);
	}//End if
}//End In

void Post(node *n)
{
	if (n!=NULL)
	{
		Post(n->left);
		Post(n->right);
		cout<<n->val<<"  "<<endl;
	}//End if
}//End Post

int main()
{
	q.front=0;
	q.rear=0;
	int value;
	int ch;
	node *root=new node;

    cout<<endl;
	cout<<"Tree"<<endl; 
	cout<<"Enter the value of root node :"<<endl;
	cin>>value;
	root->val=value;
	root->left=NULL;
	root->right=NULL;
	do
	{
	    cout<<"Please choose an option:"<<endl;
		cout<<"1. Insert : "<<endl;
		cout<<"2. Breadth First"<<endl;
		cout<<"3. Preorder Depth First"<<endl;
		cout<<"4. Inorder Depth First"<<endl;
		cout<<"5. Postorder Depth First"<<endl;
        cin>>ch;
		switch(ch)
		{
			case 1:
				int x;
				char pos;
				cout<<"Enter the value to be Inserted : "<<endl;
				cin>>x;
				cout<<"Left or Right of Root : "<<endl;
				cin>>pos;
				if(pos=='l')
					CreateTree(root, root->left, x, pos);
				else if(pos=='r')
					CreateTree(root, root->right, x, pos);
				break;
			case 2:
				BFT(root);
				break;
			case 3:
				Pre(root);
				break;
			case 4:
				In(root);
				break;
			case 5:
				Post(root);
				break;
		}
	}
	while(ch!=0);

	return 0;
}//End main
