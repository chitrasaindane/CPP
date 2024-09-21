#include <iostream>
using namespace std;

struct array
{
    int a[10];
    int size;
    int length;
};

void display(struct array ar)
{
    for (int i = 0; i < ar.length; i++)
    {
        cout << ar.a[i] << " ";
    }
    cout << endl;
}

void Delete(struct array *ar, int index)
{
    for (int i = index; i < ar->length; i++)
    {
        ar->a[i] = ar->a[i + 1];
    }
    ar->length--;
}

int main()
{
    struct array arr = {{1, 2, 3, 4, 5, 6, 7}, 10, 7};
    display(arr);
    Delete(&arr , 1);
    display(arr);
    
}