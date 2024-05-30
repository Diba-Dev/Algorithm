// TOPIC : matrix multiplication


#include <bits/stdc++.h>
using namespace std;

void metrixMulti()
{
    cout << "------MATRIX MULTIPLICATION-------" << endl;
    int Row = 0;
    int Col = 0;
    cout << "Enter the size of Row: ";
    cin >> Row;
    cout << "Enter the size of Cloumn: ";
    cin >> Col;
    int Array1[Row][Col];
    int Array2[Row][Col];
    int ArrayMul[Row][Col];

    cout << "Enter the elements of Array 1:" << endl;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cin >> Array1[i][j];
        }
    }

    cout << "Enter the elements of Array 2:" << endl;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cin >> Array2[i][j];
        }
    }

    cout << "The Multiplication of the two Array is :" << endl;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            ArrayMul[i][j] = Array1[i][j] * Array2[i][j];
            cout << ArrayMul[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int ch;
    cout << "Option: " << endl;
    cout << "Metrix Multiplication" << endl;

    metrixMulti();

    return 0;
}
