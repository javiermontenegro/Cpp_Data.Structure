/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement stack using linked list.
*********************************************************************/

#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
};


node *top;

void push(int x)
{
	node *n = new node;
	n->val=x;
	n->next=top;
	top=n;
}//End push

void pop()
{
	if (top==NULL)
	{
		cout<<"\nUnderflow";
	}
	else
	{
		node *t = top;
		cout<<"\n"<<t->val<<" deleted";
		top=top->next;
		delete t;
	}//End if
}//End pop

void show()
{
	node *t=top;
	while(t!=NULL)
	{
		cout<<t->val<<"\n";
		t=t->next;
	}//End while
}//End show

int main()
{
	int ch, x;
	do
	{
	    cout<<endl;
		cout<<"Stack Linked List"<<endl;
		cout<<"Please choose an option:"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Print"<<endl;
		cin>>ch;
		if (ch==1)
		{
			cout<<"\nInsert : ";
			cin>>x;
			push(x);
		}
		else if (ch==2)
		{
			pop();
		}
		else if (ch==3)
		{
			show();
		}//End if
	}
	while(ch!=0);

	return 0;
}//End main

