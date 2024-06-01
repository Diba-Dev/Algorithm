//TOPIC: Implementation of Stack
#include <bits/stdc++.h>
using namespace std;

void Push(int Stack[], int &stackPointer, int size)
{
    if (stackPointer == size)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        cout << "Push an element: ";
        cin >> Stack[stackPointer];
        cout << Stack[stackPointer] << " Push completed" << endl
             << endl;
        stackPointer++;
    }
}

void Pop(int Stack[], int &stackPointer)
{
    if (stackPointer == 0)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        stackPointer--;
        cout << Stack[stackPointer] << " Pop completed" << endl
             << endl;
    }
}

void Display(int Stack[], int stackPointer)
{
    if (stackPointer == 0)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Displaying stack elements:" << endl;
        for (int i = 0; i < stackPointer; i++)
        {
            cout << Stack[i] << endl;
        }
    }
}

int main()
{
    int size;
    cout << "Stack Size: ";
    cin >> size;
    int Stack[size], stackPointer = 0;

    int Option = 0;
    cout << endl
         << "1) Push \n2) Pop \n3) Top \n4) Size \n5) Display \n6) Exit" << endl;
    while (Option != 6)
    {
        cout << "Select Option: ";
        cin >> Option;

        switch (Option)
        {
        case 1:
            Push(Stack, stackPointer, size);
            break;
        case 2:
            Pop(Stack, stackPointer);
            break;
        case 3:
            cout << "TOP element is: " << Stack[stackPointer - 1] << endl;
            break;
        case 4:
            cout << "Size of the Stack is: " << stackPointer << endl;
            break;
        case 5:
            Display(Stack, stackPointer);
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option, try again." << endl;
            break;
        }
    }

    return 0;
}
