// TOPIC : Insertion Sort

#include <bits/stdc++.h>
using namespace std;


void display(int array[],int size){
    int boxWidth = 4;

    for (int i = 0; i < size; ++i) {
        cout << "+----"; 
    }
    cout << "+" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "| " <<setw(boxWidth - 2)<< array[i] << " ";
    }
    cout << "|" << endl;

    // Print the bottom border
    for (int i = 0; i < size; ++i) {
        cout << "+----";  // Adjust the number of '-' according to boxWidth
    }
    cout << "+" << endl;
}

void InsertionSort(int array[], int size)
{

    for (int i = 1; i < size; i++)
    {
        cout<<"pass["<<i<<"] : "<<endl;
        display(array,size);

        int key = array[i];
        int j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;        
    
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
    cout << "The shorted array is: " << endl;
    InsertionSort(array, size);
    cout<<endl<<"The shorted array after pass["<<size<<"] is: "<<endl;
    display(array,size);

    return 0;
}