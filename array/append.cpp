#include<iostream>
using namespace std;

struct array{
    int a[10];
    int size;
    int length;
};

void display( struct array ar)
{
    for(int i = 0 ; i< ar.length ; i++)
    {
        cout<< ar.a[i]<<" ";
    }
    cout<<endl;
}

void append(struct array *ar , int x)
{
   if(ar->length < ar->size)
    {
        ar->a[ar->length]=x;
        ar->length++;
    }
}

int main()
{ 
    struct array ar = {{1,2,3,4} , 10 , 4};
    display(ar);
    append(&ar , 400);
    display(ar);
 
}