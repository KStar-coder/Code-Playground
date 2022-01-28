#include <iostream>
#include <stdlib.h>
using namespace std;

void BS(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main()
{
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BS(arr, n);
    cout << "\n The swapped elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}