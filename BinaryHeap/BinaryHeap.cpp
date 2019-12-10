/*********************************************************************
* Filename:   BinaryHeap.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement binary heap.
*********************************************************************/

#include<iostream> 
#include<climits> 
using namespace std; 
  
void swap(int *x, int *y); 
  
class MinHeap 
{ 
    int *harr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap 
public: 
    MinHeap(int capacity); 
  
    void MinHeapify(int ); 
  
    int parent(int i) { return (i-1)/2; } 
  
    int left(int i) { return (2*i + 1); } 
  
    int right(int i) { return (2*i + 2); } 
  
    int extractMin(); 
  
    void decreaseKey(int i, int new_val); 
  
    int getMin() { return harr[0]; } 
  
    void deleteKey(int i); 
  
    void insertKey(int k); 
};//End class MinHeap 
  
MinHeap::MinHeap(int cap) 
{ 
    heap_size = 0; 
    capacity = cap; 
    harr = new int[cap]; 
}//End MinHeap 
  
void MinHeap::insertKey(int k) 
{ 
    if (heap_size == capacity) 
    { 
        cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    }//End if 
  
    heap_size++; 
    int i = heap_size - 1; 
    harr[i] = k; 
  
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    }//End while 
}//End insertKey 
  
void MinHeap::decreaseKey(int i, int new_val) 
{ 
    harr[i] = new_val; 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    }//End while 
}//End decreaseKey 
  
int MinHeap::extractMin() 
{ 
    if (heap_size <= 0) 
        return INT_MAX; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    }//End if 
  
    int root = harr[0]; 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    MinHeapify(0); 
  
    return root; 
}//End extractMin 
  
  
void MinHeap::deleteKey(int i) 
{ 
    decreaseKey(i, INT_MIN); 
    extractMin(); 
}//End deleteKey 
  
void MinHeap::MinHeapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && harr[l] < harr[i]) 
        smallest = l; 
    if (r < heap_size && harr[r] < harr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&harr[i], &harr[smallest]); 
        MinHeapify(smallest); 
    }//End if 
}//End MinHeapify 
  
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}//End swap 
  
int main() 
{ 
    MinHeap h(11); 

    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    
    cout << "Binary Heap" << endl;
    cout<<endl;
    cout << "Min Heap: " << endl; 

    cout << h.extractMin() << endl; 
    cout << h.getMin() << endl; 
    
    h.decreaseKey(2, 1); 
    
    cout << h.getMin() << endl; 
    return 0; 
}//End main 
