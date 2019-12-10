/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement recurse and reverse linked list.
*********************************************************************/

#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
};

node *start;

void insert(int x)
{
	node *t=start;
	if (start!=NULL)
	{
		while(t->next!=NULL)
		{
			t=t->next;
		}//End while

		node *n= new node;
		t->next=n;
		n->val=x;
		n->next=NULL;
	}
	else
	{
		node *n= new node;
		n->val=x;
		n->next=NULL;
		start=n;
	}//End if
}//End insert

void reverse(node *p, node *q)
{
	if (q->next == NULL)
	{
		q->next=p;
		p->next=NULL;
		start=q;
		return;
	}
	else
	{
		reverse(q, q->next);
		q->next=p;
		p->next=NULL;
	}//End if
}//End reverse

void show()
{
	node *t=start;
	while(t!=NULL)
	{
		cout<<t->val<<"\t";
		t=t->next;
	}//End while
}//End show

int main()
{
    cout<<endl;
	cout<<"Recursive Reverse Linked List"<<endl;
	
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);

	reverse(start, start->next);
    show();
    cout<<endl;

	return 0;
}//End main
