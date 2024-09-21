#include <iostream>
using namespace std;

struct array
{
    int a[10];
    int size;
    int length;
};

void insert(struct array *arr, int index, int value)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->a[i] = arr->a[i - 1];
        }
        arr->a[index] = value;
        arr->length++;
    }
}

void display(struct array ar)
{
    for (int i = 0; i < ar.length; i++)
    {
        cout << ar.a[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct array ar = {{1, 2, 3, 4}, 10, 4};
    display(ar);
    insert(&ar, 2, 400);
    display(ar);
}