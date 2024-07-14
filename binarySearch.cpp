// TOPIC : Binary Search

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int x){
    if (high >= low){
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);
    }
}
    void bubbleSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    int main()
    {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        if (n <= 0)
        {
            cout << "Array size must be greater than 0." << endl;
            return 1;
        }

        int *array = new int[n];

        for (int i = 0; i < n; ++i)
        {
            cout << "Enter element for position array[" << i << "] = ";
            cin >> array[i];
        }

        // Sorting the array using Bubble Sort
        bubbleSort(array, n);

        cout << "The sorted array is:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }

        int target;
        cout << endl
             << "Enter the element you are searching for: ";
        cin >> target;

        int result = binarySearch(array, 0, n - 1, target);

        if (result == -1)
            cout << "Element is not present in array" << endl;
        else
            cout << "Element is present at index " << result << endl;

        delete[] array; // Free the dynamically allocated memory

        return 0;
    }
