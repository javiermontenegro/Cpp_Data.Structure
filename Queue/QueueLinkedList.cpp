/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement queue using linked list.
*********************************************************************/

#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
};

node *front, *rear;

void Enque(int x)
{
	if (rear==NULL)
	{
		node *n= new node;
		n->val=x;
		n->next=NULL;
		rear=n;
		front=n;
	}
	 else
	{

		node *n = new node;
		n->val=x;
		n->next=NULL;
		rear->next=n;
		rear=n;
	}//End if
}//End Enque

void Deque()
{
	if (rear==front)
	{
		cout<<"\nUnderflow";
	}
	 else
	{
		node *t = front;
		cout<<"\n"<<t->val<<" deleted";
		front=front->next;
		delete t;
	}//End if
}//End Deque

void show()
{
	node *t=front;
	while(t!=NULL)
	{
		cout<<t->val<<"\t";
		t=t->next;
	}//End while
}//End show

int main()
{
	int ch, x;
	do
	{
	    cout<<endl;
		cout<<"Queue Linked List"<<endl;
		cout<<"Please choose an option:"<<endl;
		cout<<"1. Enque"<<endl;
		cout<<"2. Deque"<<endl;
		cout<<"3. Print"<<endl;
		cin>>ch;
		if (ch==1)
		{
			cout<<"\nInsert : ";
			cin>>x;
			Enque(x);
		}
		 else if (ch==2)
		{
			Deque();
		}
		 else if (ch==3)
		{
			show();
		}//End if
	}
	while(ch!=0);

	return 0;
}//End main

