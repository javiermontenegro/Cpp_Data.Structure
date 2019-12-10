/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement linked list.
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

void remove(int x){

	if( start == NULL ){
		cout<<"\nLinked List is empty\n";
		return ;
	}
	else if( start->val == x ){
		node *temp = start;
		start = start->next;
		delete temp;
		return ;
	}//End if

	node *temp = start, *parent = start;

	while( temp != NULL && temp->val != x ){
		parent = temp;
		temp = temp->next;
	}//End while

	if( temp == NULL ){
		cout <<endl <<x <<" not found in list\n";
		return ;
	}//End if

	parent->next = temp->next;
	delete temp;
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

int main()
{
	int choice, x;
	do
	{
	    cout<<endl;
		cout<<"Linked List"<<endl;
		cout<<"Please choose an option:"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Print"<<endl;
		cout<<"0. Exit"<<endl;
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
			case 4 : 	show();	
					cout<<"\n";	break;
		}//End switch
	}
	while(choice!=0);

	return 0;
}//End main
