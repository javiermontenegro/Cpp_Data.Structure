/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement array linked list.
*********************************************************************/

/* The difference between the pointer implementation of linked list and array implementation of linked list:
 1. The NULL is represented by -1;
 2. Limited size. We can reuse the nodes that are to be deleted by again linking it back to the list.
*/

#include<iostream>
using namespace std;
struct Node{
    int data;
    int next;
};

Node AvailArray[100];    //array that will act as nodes of a linked list.
int head=-1;
int avail=0;

void initialise_list()
{
    for(int i=0;i<=98;i++)
    {
        AvailArray[i].next=i+1;
    }//End for

    AvailArray[99].next=-1; //indicating the end of the linked list.    
}//End initialise_list

int getnode()      
{
    int NodeIndexToBeReturned=avail;
    avail=AvailArray[avail].next;
    
    return NodeIndexToBeReturned;
}//End getnode

void freeNode(int nodeToBeDeleted)     
{
    AvailArray[nodeToBeDeleted].next=avail;
    avail=nodeToBeDeleted;
}//End freeNode

void insertAtTheBeginning(int data)    
{
    int newNode=getnode();
    AvailArray[newNode].data=data;
    AvailArray[newNode].next=head;
    head=newNode;    
}//End insertAtTheBeginning

void insertAtTheEnd(int data)
{
    int newNode=getnode();
    int temp=head;
    while(AvailArray[temp].next!=-1)
    {
        temp=AvailArray[temp].next;
        
    }//End while

    AvailArray[newNode].data=data;
    AvailArray[newNode].next=-1;
    AvailArray[temp].next=newNode;
}//End insertAtTheEnd

void display()
{
    int temp=head;
    while(temp!=-1)
    {
        cout<<AvailArray[temp].data<<"->";
        temp=AvailArray[temp].next;
    }//End while

    cout<<"-1"<<endl;;
}//End display

int main()
{   initialise_list();
    int x,y,z;
    for(;;)
    {
        cout<<endl;
        cout<<"Array Linked List"<<endl;
        cout<<"Please choose an option:"<<endl;
        cout<<"1. Insert At The Beginning"<<endl;
        cout<<"2. Insert At The End"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>z;
        switch(z)
        {
            case 1:
                cout<<"Enter the number you want to enter"<<endl;
                cin>>x;
                insertAtTheBeginning(x);
                break;
            case 2:
                cout<<"Enter the number you want to enter"<<endl;
                cin>>y;
                insertAtTheEnd(y);
                break;
            case 3:
                cout<<"The linked list contains the following element in order"<<endl;
                display();
                break;
            case 4:
                exit(0);
            default:
                cout<<"The entered choice is not correct"<<endl;
                
                
        }//End switch
    }//End for
}//End main
