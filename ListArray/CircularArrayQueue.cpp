/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement circular queue using array.
*********************************************************************/

#include<iostream>
using namespace std;

int queue[10];
int front=0;
int rear=0;
int count=0;

void Enque(int x)
{
	if(count==10)
	{
		cout<<"\nOverflow";
	}
	else
	{
		queue[rear]=x;
		rear=(rear+1)%10;
		count++;
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
		cout<<"\n"<<queue[front]<<" deleted";
		front=(front+1)%10;
		count--;
	}//End if
}//End Deque

void show()
{
	for (int i = 0; i<count; i++)
	{
	    cout<<queue[(i+front)%10]<<"\t";
	}//End for
}//End show

int main()
{
	int ch, x;
	do
	{
	    cout<<endl;
		cout<<"Circular Array Queue"<<endl;
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

