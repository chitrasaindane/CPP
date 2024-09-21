#include<iostream>
using namespace std;

void display(int a[],int  n)
{
    for(int i=0; i<n;i++)
     cout<< a[i]<<" ";
}

void insert(int a[], int n ,int val)
{
 int i= n-1;
 
 while( i>=0 && a[i]>val)
 {
  a[i+1]=a[i];
  i--;
 }
 a[i+1]=val;
 
 display(a,n+1);
}

int main()
{
 int a[7]={1,10,23,56,88,98};
 insert(a,6,20);
}