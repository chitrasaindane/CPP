#include<iostream>
using namespace std;
void display(int a[],int  n)
{
    for(int i=0; i<n;i++)
     cout<< a[i]<<" ";
}

void mergearr(int a[], int b[], int m ,int n)
{
    int i=0,j=0,k =0;
    int* c = new int[m+n];
    while(i<m && j<n)
    {
        if(a[i]<b[j])
          c[k++]=a[i++];
        else 
          c[k++]=b[j++];
    }
    
    for(; i<m ; i++)
    { 
        c[k++]=a[i];
    }
    for(;j<n;j++)
    {
        c[k++]=b[j];
    }
  display(c,m+n);
  delete[] c;
}

int main()
{
    int a[]={1,2,7,98,100};
    int b[]={4,6,8,9,28};
    mergearr(a,b,5,5);
}