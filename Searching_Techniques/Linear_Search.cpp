#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // index found
        }
    }
    return -1; // if index not found
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = linearSearch(arr, n, key);

    if (result != -1)
        cout << "Element "<<key<<" found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}