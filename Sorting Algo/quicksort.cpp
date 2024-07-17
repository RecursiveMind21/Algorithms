#include<iostream>
#include<vector>
using namespace std;

int parition(vector<int>&arr, int start, int end){
    int pivot = arr[start];
    int count = 0;
    for(int i = start+1; i<=end; i++){
        if(arr[i] <= arr[start])
            count++;
    }   
    int pivotindex = start+count;
    swap(arr[start],arr[start+count]);

    //sort
    int i = start, j = end;
    while(i< pivotindex && j<pivotindex){
        while(arr[i] <= arr[start]){
            i++;
        }
        while(arr[j] > arr[start]){
            j--;
        }
        if(i < pivotindex && j > pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}

void quickSort(vector<int> &arr, int start , int end){

    if(start >= end){
        return ;
    }
    
    int count = parition(arr,start,end);

    //left part
    quickSort(arr,start,count-1);
    //right part
    quickSort(arr,count+1,end);

}   

int main(){
    vector<int> arr{10,4,5,8,23,80};
    int size = arr.size();

    cout << "Before Sorting: ";
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }   cout << endl;

    quickSort(arr,0,size-1);

    cout << "After Sorting: ";
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }   cout << endl;

    return 0;
}   