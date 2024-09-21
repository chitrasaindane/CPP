#include<iostream>
using namespace std;
 struct array
{
    int a[10];
    int size;
    int length;
};

 int linearsearch( struct array arr , int key )
 {
   for( int i=0; i< arr.length ; i++)
   {
    if(arr.a[i]== key)
    {
        return i;
    }
    return -1;
   }
 }
int main()
{
    struct array ar = {{1, 2, 3, 4}, 10, 4};
    cout<< linearsearch( ar , 4);
}