/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement hashing.
*********************************************************************/

#include<iostream>
#include<math.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
} *head[100],*curr;

void init() {
	for(int i=0;i<100;i++)
		head[i]=NULL;
}//End init

void add(int x,int h) {
	struct Node *temp = new Node;
	temp->data = x;
	temp->next = NULL;
	if(!head[h]) {
		head[h] = temp;
		curr = head[h];
	}
	else {
		curr=head[h];
		while(curr->next)
			curr = curr->next;
		curr->next = temp;
	}//End if
}//End add

void display(int mod) {
	struct Node *temp;
	int i;
	for(i=0;i<mod;i++) {
		if(!head[i]) {
			cout<<"Key "<<i<<" is empty"<<endl;
		}
		else {
			cout<<"Key "<<i<<" has values = ";
			temp = head[i];
			while(temp->next) {
				cout<<temp->data<<" ";
				temp=temp->next;
			}//End while

			cout<<temp->data;
			cout<<endl;
		}//End if
	}//End for
}//End display

int hash_data(int x,int mod) {
	return x%mod;
}//End hash_data

void find(int x,int h) {
	struct Node *temp =head[h];
	if(!head[h]) {
		cout<<"Element not found";
		return;
	}//End if

	while(temp->data !=x && temp->next)
		temp=temp->next;
	if(temp->next)
		cout<<"Element found";
	else{
		if(temp->data == x)
			cout<<"Element found";
		else
			cout<< "Element not found";
	}//End if
}//End find	

int main(void) {
	init();
	int c,x,mod,h;
	cout<<"Enter the size of Hash Table. = ";
	cin>>mod;
	bool loop = true;
	while(loop) {
		cout<<endl;
		cout<<"Hashing table"<<endl;
		cout<<"Please choose an option:"<<endl;
		cout<<"1. Add element."<<endl;
		cout<<"2. Find element."<<endl;
		cout<<"3. Generate Hash."<<endl;
		cout<<"4. Display Hash table."<<endl;
		cout<<"5. Exit."<<endl;
		cin>>c;
		switch(c) {
			case 1:
				cout<<"Enter element to add = ";
				cin>>x;
				h = hash_data(x,mod);
				h = fabs(h);
				add(x,h);
				break;
			case 2:
				cout<<"Enter element to search = ";
				cin>>x;
				h = hash_data(x,mod);
				find(x,h);
				break;
			case 3:
				cout<<"Enter element to generate hash = ";
				cin>>x;
				cout<<"Hash of "<<x<<" is = "<<hash_data(x,mod);
				break;
			case 4:
				display(mod);
				break;
			default:
				loop = false;
				break;
		}
		cout<<endl;
	}
	
	return 0;
}//End main