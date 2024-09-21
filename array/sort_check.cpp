#include <iostream>
using namespace std;

bool sort_arr(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a[] = {1, 10, 23, 56, 88, 98};
    cout << sort_arr(a, 6);
}
