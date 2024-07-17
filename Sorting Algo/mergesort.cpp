#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& arr, int start, int mid, int end){
    //declare size
    int leftarraysize = mid - start + 1;
    int rightarraysize = end - mid;

    vector<int> leftArray(leftarraysize);
    vector<int> rightArray(rightarraysize);

    int s = start;

    //copy element
    for(int i = 0; i<leftarraysize; i++){
        leftArray[i] = arr[s++]; 
    }
    for(int i = 0; i<rightarraysize; i++){
        rightArray[i] = arr[s++]; 
    }

    //combine both array in main array
    int i = 0, j = 0, k = start;
    while(i<leftarraysize && j < rightarraysize){
        leftArray[i] < rightArray[j] ? arr[k++] = leftArray[i++] : arr[k++] = rightArray[j++];
    }

    while(i < leftarraysize){
        arr[k++] = leftArray[i++];
    }
    while(j < rightarraysize){
        arr[k++] = rightArray[j++];
    }
}

void MergeSort(vector<int>& arr, int start , int end){
    if(start >= end)
        return ;

    int mid = start + (end-start)/2;

    //break
    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,end);

    Merge(arr,start,mid,end);
}

int main(){

    vector<int> arr{10,4,23,5,6,86,9,2,4,4};
    int size = arr.size();

    cout << "Array before sorting: ";
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }   cout << endl;

    MergeSort(arr,0,size-1);

    cout << "Array after sorting: ";
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}