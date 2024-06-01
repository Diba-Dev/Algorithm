//TOPIC : QUEUE
 
#include<bits/stdc++.h>
using namespace std;

void Insert(int queue[], int& front, int& rear, int n)
{
    int val;
    if (rear == n - 1)
        cout << "Queue Overflow" << endl;
    else
    {
        if (front == -1)
            front = 0;
        cout << "Insert the element in queue: ";
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}

void Delete(int queue[], int& front, int& rear)
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    else
    {
        cout << "Element deleted from queue is: " << queue[front] << endl;
        front++;
    }
}

void Display(int queue[], int front, int rear)
{
    if (front == -1 || front > rear)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main()
{  cout<<"Enter the size of the queue: ";
    int n ;
    cin>>n;
    int queue[n];
    int front = -1, rear = -1;
    int ch;
    cout <<"1)Insert\n2)Delete\n3)Display\n4)Exit"<<endl;

    do
    {
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            Insert(queue, front, rear, n);
            break;
        case 2:
            Delete(queue, front, rear);
            break;
        case 3:
            Display(queue, front, rear);
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 4);
    
    return 0;
}
