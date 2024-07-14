//TOPIC : 
 
#include<bits/stdc++.h>
using namespace std;

int IndexofValue(int array[],int child,int size){
    for(int i = 1; i <= size; i++ ){
        if(array[i] == child){
          return i; 
        }
    }
    cout<<endl<<"element not found"<<endl;
    return 0;
}

int parentIndex(int Indexn){
    return Indexn/2;
}

int main(){
    int size;
    cout << "Put the array size: ";
    cin >> size;
    int array[size];
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter array[" << i << "] = ";
        cin >> array[i];
    }

    for (int i = 1; i<=size ; i++){
        if(i*2 >size){
            cout<<array[i]<<" is a leaf node."<<endl;
        }
        else{
            cout<<array[i]<<" = (RC) -> "<<array[i*2]<<" (LC) -> "<<array[(i*2)+1]<<endl;
        }
    }



    int child;
    cout<<"Enter the element you are searching for the parent: ";
    cin>>child;

    int Indexn = IndexofValue(array,child,size);
    int parentI = Indexn/2;
    if(parentI <= 1){
        cout<< "the given value is the root"<<endl;
    }
    cout<< "The Parent of:"<< child <<" is: "<< array[parentI]<<endl;
    if(Indexn*2 >size){
        cout<<array[Indexn]<<" is a leaf node."<<endl;
    }
    else{
        cout<<array[Indexn]<<" = (RC) -> "<<array[Indexn*2]<<" (LC) -> "<<array[(Indexn*2)+1]<<endl;    
    }



    
    

    return 0;
}