#include <iostream>
using namespace std;

struct array
{
    int a[10];
    int size;
    int length;
};

int binarysearch(int a[],int l , int h, int key)
{
   int mid;
    
    while(l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return binarysearch(a,l,mid-1,key);
        else
            return binarysearch(a,mid+1,h,key);
    }
    return -1;
}

int main()
{
     struct array arr = {{1,2,3,4,5,6,7,8,9,},10,9};
     cout << binarysearch(arr.a, 0, arr.length,5)<<endl;
}