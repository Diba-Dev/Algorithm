// TOPIC : stack push pop;

#include <bits/stdc++.h>
using namespace std;

void Push(int Stack[], int &stackPointer, int a)
{
    if (stackPointer == a)
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
        cout << Stack[stackPointer-1] << " Pop completed" << endl
             << endl;
        stackPointer--;
    }
}
void Display(int Stack[], int &stackPointer)
{
    if (stackPointer == 0)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Displying:" << endl;
        for (int i = 0; i < stackPointer; i++)
        {
            cout << Stack[i] << endl;
        }
    }
}

int main()
{
    int a;
    cout << "Stack Size: ";
    cin >> a;
    int Stack[a], stackP = 0;
    int *stackPointer = &stackP;
    int *aa = &a;

    int Option = 0;
    cout << endl
         << "1) for push \n2) for pop \n3) for display \n4) for break: " << endl;
    while (Option != 4)
    {
        cout << "Option put: ";
        cin >> Option;

        switch (Option)
        {
        case 1:
            Push(Stack, *stackPointer, *aa);
            break;
        case 2:
            Pop(Stack, *stackPointer);
            break;
        case 3:
            Display(Stack, *stackPointer);
            break;

        default:
            break;
        }
    }

    return 0;
}