#include<iostream>
using namespace std;

void sort012(int *arr, int size){

    int start = 0;
    int mid = 0;
    int end = size-1;

    while(mid < end){

        if(arr[mid] == 0){
            swap(arr[start], arr[mid]);
            start++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[end]);
            end--;
        }
    }
}

int main(){

    int size;
    size = 6;

    int* arr = new int[size];

    cout << "Enter value for array: ";
    for(int i = 0; i<6; i++){
        cin >> arr[i];
    }

    sort012(arr,size);

    cout << "Sorted Array: ";
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
}