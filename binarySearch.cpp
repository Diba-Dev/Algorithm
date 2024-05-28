//TOPIC : Binary Search
 
#include<bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
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

int main() {
    int n;
    cout << "PUT N: ";
    cin >> n;

    int* array = new int[n];

    cout << "Put the array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int find;
    cout << "Enter the element you are searching: ";
    cin >> find;

    int result = binarySearch(array, 0, n - 1, find);
    if (result == -1) {
        cout << "Element is not present in array" << endl;
    } else {
        cout << "Element is present at index " << result;
    }
    
    return 0;
}
