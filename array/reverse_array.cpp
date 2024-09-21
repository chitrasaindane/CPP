#include<iostream>
using namespace std;

void display(int a[],int  n)
{
    for(int i=0; i<n;i++)
     cout<< a[i]<<" ";
}

int reverse(int a[] , int n)
{
    int *b = new int[n];
    int i, j;

    for(i = n-1 , j =0; i>=0 ; i--, j++)
    {
        b[j]= a[i];
    }

    for(i = 0 ; i<n ; i++)
    {
        a[i]=b[i];
    }

   display(a,n);
}

/*reverse using swaping of elements*/
int reverse_2(int a[], int n)
{
    int i,j,temp;
    for(i=0,j=n-1;i<j ; i++,j--)
    {
        temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    display(a,n);
}
int main()
{
 int a[]={1,2,3,4,5,6,7};
 /* reverse(a,7); */
 cout<< "\n";
 reverse_2(a,7);
  return 0;
}