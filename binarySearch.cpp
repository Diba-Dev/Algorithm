// TOPIC : Binary Search

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Put the size of the array: ";
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter elemnt for position array[" << i << "] = ";
        cin >> array[i];
    }
    int find;
    cout << "Enter the element you are searching: ";
    cin >> find;

    int result = binarySearch(array, 0, n - 1, find);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;

    return 0;
}
