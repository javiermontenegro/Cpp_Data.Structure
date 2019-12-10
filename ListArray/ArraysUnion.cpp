/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement union of arrays.
*********************************************************************/

#include <iostream>

int main()
{
   cout<<endl;
   cout<<"Arrays Union"<<endl;

   int m,n,i=0,j=0;
   cout << "Enter size of both arrays:";
   cin >> m >> n;
   int a[m];
   int b[n];
   
   cout << "Enter elements of array 1:";
   for(i=0;i<m;i++)
       cin >>a[i];
   
   cout << "Enter elements of array 2:";
   for(i=0;i<n;i++)
       cin >> b[i];
   
   i=0;j=0;
   while((i<m)&&(j<n))
   {
     if(a[i]<b[j])
         cout << a[i++] <<" ";
     else if(a[i]>b[j])
         cout << b[j++] <<" ";
     else
     {
         cout << a[i++];
         j++;
     }//End if
   }//End while

   while(i<m)
       cout<< a[i++] <<" ";
   while(j<n)
       cout<< b[j++]<<" ";
   
   return 0;
}//End main
