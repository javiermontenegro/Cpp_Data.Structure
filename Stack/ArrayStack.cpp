/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement stack using array.
*********************************************************************/

#include<iostream>
using namespace std;

int *stack;
int top=0, size;

void push(int x)
{
	if(top==size)
	{
		cout<<"\nOverflow";
	}
	 else
	{
		stack[top++]=x;
	}//End if
}//End push

void pop()
{
	if (top==0)
	{
		cout<<"\nUnderflow";
	}
	else
	{
		cout<<"\n"<<stack[--top]<<" deleted";
	}//End if
}//End pop

void show()
{
	for (int i = 0; i < top; i++)
	{
		cout<<stack[i]<<"\n";
	}//End for
}//End show

void topmost()
{
    cout << "\nTopmost element: "<<stack[top-1];
}//End topmost

int main()
{
	cout<<"\nEnter Size of stack : ";
	cin>>size;
	stack = new int[size];
	int ch, x;
	do
	{
	    cout<<endl;
		cout<<"Array Stack"<<endl;
		cout<<"Please choose an option:"<<endl;
		cout<<"\n1. Push"<<endl;
		cout<<"\n2. Pop"<<endl;
		cout<<"\n3. Print"<<endl;
        cout<<"\n4. Print topmost element:"<<endl;
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
		}
        else if(ch==4)
        {
            topmost();
        }//End if
	}
	while(ch!=0);

	return 0;
}//End main

