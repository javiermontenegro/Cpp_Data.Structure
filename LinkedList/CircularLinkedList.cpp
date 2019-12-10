/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement circular linked list.
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
		while(t->next!=start)
		{
			t=t->next;
		}//End while

		node *n= new node;
		t->next=n;
		n->val=x;
		n->next=start;
	}
	else
	{
		node *n= new node;
		n->val=x;
		start=n;
		n->next=start;
	}//End if
}//End insert

void remove(int x)
{
	node *t=start;
	node *p;
	while(t->val!=x)
	{
		p=t;
		t=t->next;
	}//End while

	p->next=t->next;
	delete t;
}//End remove

void search(int x)
{
	node *t= start;
	int found =0;
	while(t->next!=start)
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
	do
	{
		cout<<t->val<<"\t";
		t=t->next;
	}
	while(t!=start);

}//End show

int main()
{
	int choice, x;
	do
	{
	    cout<<endl;
	    cout<<"Circular linked list"<<endl;
		cout<<"Please choose an option:"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Print"<<endl;
		
		cin>>choice; 
		switch (choice)
		{
			case 1 : 	cout<<"\nEnter the element to be inserted : ";
					 	cin>>x;
					 	insert(x);	break;
			case 2 : 	cout<<"\nEnter the element to be removed : ";
						cin>>x;
						remove(x); 	break;
			case 3 : 	cout<<"\nEnter the element to be searched : ";
						cin>>x;
						search(x); 	break;
			case 4 : show();	break;
		}//End switch
	}
	while(choice!=0);

	return 0;
}//End main
