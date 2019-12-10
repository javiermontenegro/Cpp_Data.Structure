/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement selection sort on linked list.
*********************************************************************/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* link;
    node(int d)
    {
        data = d;
        link = NULL;
    }

};//End class node

void print(node* head)
{
    node* current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current-> link;
    }//End while

    cout << endl;
}//End print

node* createlist(int n)
{
    node* head = NULL;
    node* t = NULL;
    for (int i = 0; i < n; i++)
    {
        node* temp = NULL;
        int num;
        cin >> num;
        temp = new node(num);
        if (head == NULL)
        {
            head = temp;
            t = temp;
            continue;
        }//End if

        if (t->link == NULL) t->link = temp;
        t = temp;
    }//End for

    return head;
}//End createlist

void my_selection_sort_linked_list(node* &head)
{
    node* min = head;			
    node* current = min->link;		
    node* previous = min;		
    node* temp = NULL;			

    while (min->link != NULL)			
    {
		while (current != NULL)			
        {
            if (current->data < min->data)	
            {
                if (temp == NULL)		
                {
                    if (previous == min)	
                    {
                        head = current;		
                        min->link = current->link;
                        current->link = previous;
                        min = current;
                        current = previous->link;
                    }
                    else			
                    {
                        head = current;			
                        previous->link = current->link;
                        current->link = min;
                        min = current;
                        current = previous->link;
                    }//End if
                }
                else					
                {
                    temp->link = current;
                    previous->link = current->link;
                    current->link = min;
                    min = current;
                    current = previous->link;
                }//End if
            }
            else				
            {
                previous = previous->link;
                current = current->link;
            }//End if
        }//End while

        temp = min;
        min = min->link;
        previous = min;
        current = min->link;
    }//End while
}//End my_selection_sort_linked_list

int main()
{
    cout<<endl;
    cout<<"Selection Sort on Linked List"<<endl;

    node* head = NULL;
    int n;
    cout << "Enter the no. of nodes : " << endl;    
    cin >> n;
    
    if (n == 0) return 0;
    head = createlist(n);                   
    
    cout << "Original list is : " << endl;
    print(head);                            
    my_selection_sort_linked_list(head);    
    
    cout << "Sorted list is : " << endl;
    print(head);

    return 0;
}//End main