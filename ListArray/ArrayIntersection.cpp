/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement intersection of arrays.
*********************************************************************/

#include <iostream>

int main()
{
  cout<<endl;
  cout<<"Arrays Intersection"<<endl;

  int i,j,m,n;
  cout <<"Enter size of array 1:";
  cin >> m;
  
  cout <<"Enter size of array 2:";
  cin >> n;
  int a[m];
  int b[n];
  
  cout <<"Enter elements of array 1:";
  for(i=0;i<m;i++)
      cin >> a[i];
  for(i=0;i<n;i++)
      cin >> b[i];
  
  i=0;j=0;
  while((i<m)&&(j<n))
  {
    if(a[i]<b[j])
     i++;
    else if(a[i]>b[j])
     j++;
    else
    {
      cout << a[i++]<<" ";
      j++;
    }//End if
  }//End while

  return 0;
}//End main
