#include<iostream>
using namespace std;
void display(int a[],int  n)
{
    for(int i=0; i<n;i++)
     cout<< a[i]<<" ";
}

void PN_separate(int a[],int n)
{
 int i=0;
 int j = n-1;
 int temp;
 while(i<j)
 {
    while(a[i]<0){i++;}
    while(a[j]>=0){j--;}
    if(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
 }
 display(a,n);
}



int main()
{
 int a[]={-1,2,-3,-4,5,6,9,-6};
 PN_separate(a,8);
}