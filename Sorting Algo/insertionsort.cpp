#include<iostream>
using namespace std;

void insertionsort(int *arr, int size){
    for(int i = 1; i<size; i++){
        int temp = arr[i];
        int index = i;
        for(int j = i-1; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
                index = j;
            }
            else{
                index = j;
                break;
            }
        }
        arr[index] = temp;
    }
}

void printarray(int *arr, int size){
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
}

void scanarray(int *arr, int size){
    cout << "Enter the elements for array: ";
    for(int i = 0; i<size; i++){
        cin >> arr[i];
    }
}

int main(){

    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int*arr = new int[size];

    scanarray(arr,size);
    cout << "Array before sorting: ";
    printarray(arr,size);
    cout << "Array after sorting: ";
    insertionsort(arr,size);
    printarray(arr,size);

    return 0;
}