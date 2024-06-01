// TOPIC: quickshort

#include <bits/stdc++.h>
using namespace std;

void swapF(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (true)
    {
        while (i <= high && a[i] <= pivot)
        {
            i++;
        }
        while (j >= low && a[j] > pivot)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swapF(a[i], a[j]); //basic swap
    }
    swapF(a[low], a[j]);
    return j; //return the position of the pivot  
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(a, low, high);
        quickSort(a, low, pivotIndex - 1); //do the left side work of the pivot index
        quickSort(a, pivotIndex + 1, high); //do the right sidde work of the pivod index
    }
}

int main()
{
    int n;
    cout << "PUT the size of the array : ";
    cin >> n;
    int ar[n];
    cout << "Put the array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    quickSort(ar, 0, n - 1); // Q(array,Low,High)

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;

    return 0;
}