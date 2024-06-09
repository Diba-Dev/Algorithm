void InsertionSort(int array[], int size){
    for (int i = 1; i < size; i++){
        int key = array[i];
        int j = i - 1;
        cout << "pass[" << i << "] : " << endl;

        while (j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            display(array, size);
            j--;
        }
        array[j + 1] = key;
        display(array, size);
    }
}