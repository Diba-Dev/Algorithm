//TOPIC: Linear Search Algorithm

#include <bits/stdc++.h>
using namespace std;

int search(int array[], int N, int find)
{
    for (int i = 0; i < N; i++)
        if (array[i] == find)
            return i;
    return -1;
}

int main(void)
{
    int N,find;
    cout<<"Put the size of array: ";
    cin>>N;
    int array[N];
    for (int i = 0; i < N; i++)
    {
        cout<<"Enter elemnt for position array["<<i<<"] = ";
        cin>>array[i];
    }
    cout<<"The Element you are searching for: ";
    cin>>find;
    

    int result = search(array, N, find);
    (result == -1)
        ? cout << "Element is not found"
        : cout << "Element is in " << result;
    return 0;
}
