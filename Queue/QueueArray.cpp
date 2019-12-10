/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement queue using array.
*********************************************************************/

#include<iostream>
using namespace std;

int queue[10];
int front=0;
int rear=0;

void Enque(int x)
{
	if(rear==10)
	{
		cout<<"\nOverflow";
	}
	else
	{
		queue[rear++]=x;
	}//End if
}//End Enque

void Deque()
{
	if (front==rear)
	{
		cout<<"\nUnderflow";
	}	
	 else
	{
		cout<<"\n"<<queue[front++]<<" deleted";
		for (int i = front; i < rear; i++)
		{
			queue[i-front]=queue[i];
		}//End for

		rear=rear-front;
		front=0;
	}//End if
}//End Deque

void show()
{
	for (int i = front; i < rear; i++)
	{
		cout<<queue[i]<<"\t";
	}//End for
}//End show

int main()
{
	int ch, x;
	do
	{
	    cout<<endl;
		cout<<"Queue Array"<<endl;
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

