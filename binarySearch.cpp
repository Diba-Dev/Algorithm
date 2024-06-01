#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid-point to avoid overflow

        if (arr[mid] == x)
            return mid; // Element found at mid

        if (arr[mid] < x)
            low = mid + 1; // Narrow search to upper half
        else
            high = mid - 1; // Narrow search to lower half
    }

    return -1; // Element not found
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be greater than 0." << endl;
        return 1;
    }

    int array[n];

    for (int i = 0; i < n; ++i) {
        cout << "Enter element for position array[" << i << "] = ";
        cin >> array[i];
    }

    // Sorting the array using Bubble Sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    int find;
    cout << "Enter the element you are searching for: ";
    cin >> find;

    int result = binarySearch(array, 0, n - 1, find);

    if (result == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << result << endl;

    return 0;
}
