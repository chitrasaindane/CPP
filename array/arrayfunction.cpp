#include<iostream>
using namespace std;
/*Function on array*/

int maximum(int a[], int n)
{
 int max = a[0];
 for(int i =1 ; i<n ; i++)
 {
    if(a[i]>max)
    {
        max=a[i];
    }
 }
 return max;
}

int sum(int a[] , int n)
{
    if ( n<0)
      return 0;
    else
      return sum(a,n-1)+a[n];
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    cout<< maximum(a,9)<<endl;

    cout<< sum(a,8);
}