#include<iostream>
using namespace std;

int missing_ele(int a[], int n)
{
    int diff = a[0] - 0;
    for (int i = 0; i < n - 1; i++)
    {
        // Check if the difference between consecutive elements is greater than 1
        while (a[i + 1] - a[i] > 1) {
            cout << a[i] + 1 << " ,";
            a[i]++;  // Increment current value to move toward the next element
        }
    }
    return 0; // Optionally return 0 (no missing elements if called elsewhere)
}

/*
int missing_ele(int a[], int n)
{
 int diff = a[0]-0;
 for(int i=0; i< n; i++)
 {
   if(a[i]-i != diff)
   {
    cout<< diff + i <<" ,";
    diff= a[i]-i;
   }
 }
 return 0;

}
*/

int main()
 {
    int n;
    cout<<"Enter the number of elements in the array: " ;
    cin>>n;
    int a[n];
    cout << "Enter " << n << " elements(sorted):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }
    
    cout<<"Missing element  is : ";
    cout  << missing_ele(a, n );
    
 }