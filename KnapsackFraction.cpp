#include <bits/stdc++.h>
using namespace std;

struct Object {
    int objectNo;
    double profits;
    double weight;
    double perW; 
};

void sortObjects(Object Item[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (Item[i].perW < Item[j].perW) {
                Object temp = Item[i];
                Item[i] = Item[j];
                Item[j] = temp;
            }
        }
    }
}

int main() {
    cout << "Size: ";
    int size;
    cin >> size;

    Object Item[size];
    double X[size]; 

    for (int i = 0; i < size; i++) {
        X[i] = 0;
        Item[i].objectNo = i;
        cout << "(profit weight) for object [" << i << "]: ";
        cin >> Item[i].profits >> Item[i].weight;
        Item[i].perW = Item[i].profits / Item[i].weight;
    }

    double capacity;
    cout << "Knapsack capacity: ";
    cin >> capacity;

    sortObjects(Item, size);

    double totalProfit = 0;

    for (int i = 0; i < size; i++) {
        if (capacity == 0) {
            break;
        }

        if (Item[i].weight <= capacity) {
            X[i] = 1;
            totalProfit += Item[i].profits;
            capacity -= Item[i].weight;
        } 
        
        else {
            X[i] = capacity / Item[i].weight;
            totalProfit += Item[i].profits * X[i];
            capacity = 0; 
        }
    }

    cout<<"Fraction: ";
    for (int i = 0; i < size; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    cout << "Total profit: " << totalProfit << endl;

    return 0;
}
