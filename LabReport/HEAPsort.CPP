//TOPIC : Heap Sort Algorithm
 
#include<bits/stdc++.h>
using namespace std;

void swap(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void Heapify(int array[], int size, int i)
{
    int largest = i;         
    int lChild = 2 * i + 1;  
    int rChild = 2 * i + 2; 

    if (lChild < size && array[lChild] > array[largest])
        largest = lChild;

    if (rChild < size && array[rChild] > array[largest])
        largest = rChild;

    if (largest != i)
    {
        swap(array, i, largest);  
        Heapify(array, size, largest);  
    }
}

void heapSort(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        Heapify(array, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        swap(array, 0, i);

        Heapify(array, i, 0);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int array[size];
    cout << "Enter the values: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    // Perform heap sort
    heapSort(array, size);

    // Display the sorted array
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
