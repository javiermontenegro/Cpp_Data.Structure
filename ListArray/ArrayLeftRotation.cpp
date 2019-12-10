/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement array left rotation.
*********************************************************************/

#include<iostream>
using namespace std;

int main(){
	
    cout<<endl;
	cout<<"Array Left Rotation"<<endl;

	int n,k;
	cout<<"Enter size of array=\t";
	cin>>n;
	
	cout<<"Enter Number of indeces u want to rotate the array to left=\t";
	cin>>k;
	
	int a[n];
	cout<<"Enter  elements of array=\t";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}//End for

	int temp=0;
	for(int i=0;i<k;i++){
	temp=a[0];
		for(int j=0;j<n;j++){
			if(j==n-1){
			   a[n-1]=temp;
			}
			else{
			   a[j]=a[j+1];
			}//End if
		}//End for

	}cout<<"Your rotated array is=\t";
	for(int j=0;j<n;j++){
		cout<<a[j]<<" ";
	}//End for

	getchar();
	return 0;
}//End main
