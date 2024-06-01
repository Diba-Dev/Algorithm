// TOPIC : Insertion Sort
// Insertion short did not swap it just shift

#include <bits/stdc++.h>
using namespace std;

void display(int array[], int size);
void InsertionSort(int array[], int size)
{

    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        cout << "pass[" << i << "] : " << endl;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            display(array, size);
            j--;
        }
        array[j + 1] = key;
        display(array, size);
    }
}

int main()
{
    int size;
    cout << "Put the array size: ";
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter elemnt for position array[" << i << "] = ";
        cin >> array[i];
    }
    cout << "The Provided array is: " << endl;
    display(array, size);

    InsertionSort(array, size);
    cout << endl
         << "The shorted array after pass[" << size << "] is: " << endl;
    cout << "The shorted array is: " << endl;
    display(array, size);

    return 0;
}

void display(int array[], int size)
{
    int boxWidth = 4;

    for (int i = 0; i < size; ++i)
    {
        cout << "+----";
    }
    cout << "+" << endl;

    for (int i = 0; i < size; ++i)
    {
        cout << "| " << setw(boxWidth - 2) << array[i] << " ";
    }
    cout << "|" << endl;

    // Print the bottom border
    for (int i = 0; i < size; ++i)
    {
        cout << "+----"; // Adjust the number of '-' according to boxWidth
    }
    cout << "+" << endl;
}