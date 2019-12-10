/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement doubly linked list.
*********************************************************************/

#include<iostream>
using namespace std;

struct node
{
	int val;
	node *prev;
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
		n->prev=t;
		n->val=x;
		n->next=NULL;
	}
	else
	{	
		node *n= new node;
		n->val=x;
		n->prev=NULL;
		n->next=NULL;
		start=n;
	}//End if
}//End insert

void remove(int x)
{
	node *t=start;
	while(t->val!=x)
	{
		t=t->next;
	}//End while

	t->prev->next=t->next;
	t->next->prev=t->prev;
	delete t;
}//End remove

void search(int x)
{
	node *t= start;
	int found =0;
	while(t!=NULL)
	{
		if(t->val==x)
		{
			cout<<"\nFound";
			found=1;
			break;
		}//End if

		t=t->next;
	}//End while

	if(found==0)
	{
		cout<<"\nNot Found";
	}//End if
}//End search

void show()
{
	node *t=start;
	while(t!=NULL)
	{
		cout<<t->val<<"\t";
		t=t->next;
	}//End while
}//End show

void reverseShow()
{
	node *t=start;
	while(t->next!=NULL)
	{
		t=t->next;
	}//End while

	while(t!=NULL)
	{
		cout<<t->val<<"\t";
		t=t->prev;
	}//End while
}//End reverseShow

int main()
{
	int choice, x;
	do
	{
	    cout<<endl;
		cout<<"Doubly linked list"<<endl;
		cout<<"Please choose an option:"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Forward print"<<endl;
		cout<<"5. Reverse print"<<endl;
		
		cin>>choice; 
		switch (choice)
		{
			case 1 : 	cout<<"\nEnter the element to be inserted : ";
					 	cin>>x;;
					 	insert(x);	break;
			case 2 : 	cout<<"\nEnter the element to be removed : ";
						cin>>x;
						remove(x); 	break;
			case 3 : 	cout<<"\nEnter the element to be searched : ";
						cin>>x;
						search(x); 	break;
			case 4 : 	show();		break;
			case 5 : 	reverseShow();	break;
		}//End switch
	}
	while(choice!=0);

	return 0;
}//End main
