#include<iostream>
using namespace std;

int missing_ele(int a[], int n)
{
 int diff=a[0]-0;
 for(int i=0; i<n ; i++)
 {
    if(a[i]-i != diff)
    {
     
      return i+ diff;
    }
 }
 return -1;
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array: " ;
    cin>>n;
    int a[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }
    
    cout<<"Missing element  is : "<< missing_ele(a, n );
    


}