//TOPIC : 
 
#include<bits/stdc++.h>
using namespace std;
void swap(int array[], int a, int b){
    int aA = array[a];
    int bB = array[b];
    array[b] = aA;
    array[a] = bB;
}

void Create_heap(int array[], int size, int i)
{

    int largest = i;

    int lChild = 2 * i + 1;

    int rChild = 2 * i + 2;

    if (lChild < size && array[lChild] > array[largest])
        largest = lChild;

    if (rChild < size && array[rChild] > array[largest])
        largest = rChild;

    if (largest != i) {
        swap(array, i, largest);
        Create_heap(array, size, largest);
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int array[size];
    cout<<"enter the values: "<<endl;
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }

    for (int i = size / 2 - 1; i >= 0; i--){
        Create_heap(array, size, i);
    }

    for(int i = 0; i < size; i++ ){
        cout<< array[i]<< " ";
    }

    return 0;
}