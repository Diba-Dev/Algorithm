// TOPIC : Heap sort

#include <bits/stdc++.h>
using namespace std;
void swap(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array [b];
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

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int array[size];
    cout << "enter the values: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(array, size, i);
    }

    // The MAX_heap is: 
    cout<<"The Max_heap is: "<<endl; 
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    // The delete part:
    cout<<"The sorted heap: "<<endl;
    int size2 = size;
    int Deleted[size2] ={0};

    for (int i = 0; i < size2; i++)
    {
        Deleted[i] = array[0];
        array[0] = array[size-1];
        size--;
        for (int j = size2 / 2 - 1; j >= 0; j--)
        {
            Heapify(array, size, j);
        }
        
    }
    
    cout<<"The deleted element/ sorted array is: "<<endl;
    for (int i = 0; i < size2; i++)
    {
        cout<< Deleted[i]<< " ";
    }

    return 0;
}
