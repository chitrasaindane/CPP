#include <iostream>
using namespace std;

struct array
{
    int a[10];
    int size;
    int length;
};

int binarysearch(struct array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.a[mid])
            return mid;
        else if (key < arr.a[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
     struct array arr = {{1,2,3,4,5,6,7,8,9,},10,9};
     cout << binarysearch(arr, 7)<<" ";
}