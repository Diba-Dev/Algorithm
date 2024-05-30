// TOPIC : Bubble Sort

#include <bits/stdc++.h>
using namespace std;

void bubbleShort(int array[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j<size - i; j++)
        {
            if (array[j+1]<array[j])
            {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }   
        }
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
    cout<<"The shorted array is: "<<endl;
    bubbleShort(array, size);
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }

    return 0;
}