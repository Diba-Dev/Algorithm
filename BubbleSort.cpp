// TOPIC : Bubble Sort

#include <bits/stdc++.h>
using namespace std;
void display(int array[], int size);

void bubbleShort(int array[], int size)
{

    for (int i = 0; i < size-1; i++)
    {
        cout << "pass[" << i << "] :" << endl;
        display(array, size);
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j + 1] < array[j])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
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
        cout << "Enter array[" << i << "] = ";
        cin >> array[i];
    }
    bubbleShort(array, size);
    cout << "The shorted array is: " << endl;
    display(array, size);

    return 0;
}

void display(int array[], int size){
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

    for (int i = 0; i < size; ++i)
    {
        cout << "+----";
    }
    cout << "+" << endl;
}
