// Merging two sorted arrays

#include <iostream>

using namespace std;

void merge(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < m)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < n)
    {
        cout << b[j] << " ";
        j++;
    }
}

int main()
{
    // Here are two sorted arrays
    int a[3] = {10, 20, 35};
    int b[3] = {5, 50, 50};
    merge(a, b, 3, 3);
    return 0;
}