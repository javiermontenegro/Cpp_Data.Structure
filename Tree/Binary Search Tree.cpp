/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement binary search tree.
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

void Insert(node *n, int x)
{
	if (x<n->val)
	{
		if (n->left==NULL)
		{
			node *temp=new node;
			temp->val=x;
			temp->left=NULL;
			temp->right=NULL;
			n->left=temp;
		}
		else
		{
			Insert(n->left, x);
		}//End if
	}
	else
	{
		if (n->right==NULL)
		{
			node *temp=new node;
			temp->val=x;
			temp->left=NULL;
			temp->right=NULL;
			n->left=temp;
		}
		else
		{
			Insert(n->right, x);
		}//End if
	}//End if
}//End Insert

int findMaxInLeftST(node *n)
{
	while(n->right!=NULL)
	{
		n=n->right;
	}//End while

	return n->val;
}//End findMaxInLeftST

void Remove(node *p, node *n, int x)
{
	if (n->val==x)
	{
		if (n->right==NULL && n->left==NULL)
		{
			if (x<p->val)
			{
				p->right=NULL;
			}
			else
			{
				p->left=NULL;
			}//End if	
		}
		else if (n->right==NULL)
		{
			if (x<p->val)
			{
				p->right=n->left;
			}
			else
			{
				p->left=n->left;
			}//End if
		}
		else if (n->left==NULL)
		{
			if (x<p->val)
			{
				p->right=n->right;
			}
			else
			{
				p->left=n->right;
			}//End if
		}
		else
		{
			int y=findMaxInLeftST(n->left);
			n->val=y;
			Remove(n, n->right, y);
		}//End if
	}
	else if (x<n->val)
	{
		Remove(n, n->left, x);
	}
	else
	{
		Remove(n, n->right, x);
	}//End if
}//End Remove

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
	cout<<"Binary Search Tree"<<endl;
	cout<<"Enter the value of root node :"<<endl;
	cin>>value;
	root->val=value;
	root->left=NULL;
	root->right=NULL;
	do
	{
	    cout<<endl;
	    cout<<"Please choose an option:"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Breadth First"<<endl;
		cout<<"4. Preorder Depth First"<<endl;
		cout<<"5. Inorder Depth First"<<endl;
		cout<<"6. Postorder Depth First"<<endl;
        cin>>ch;
		int x;
		switch(ch)
		{
			case 1:
				cout<<"Enter the value to be Inserted : "<<endl;
				cin>>x;
				Insert(root, x);
				break;
			case 2:
				cout<<"Enter the value to be Deleted : "<<endl;
				cin>>x;
				Remove(root, root, x);
				break;
			case 3:
				BFT(root);
				break;
			case 4:
				Pre(root);
				break;
			case 5:
				In(root);
				break;
			case 6:
				Post(root);
				break;
		}//End switch
	}
	while(ch!=0);

	return 0;
}//End main
