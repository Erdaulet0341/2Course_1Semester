#include <iostream>
using namespace std;

void merge(int arr[], int left[], int right[]){
    int n_arr = sizeof(arr)/sizeof(int);
    int n_left = sizeof(left)/sizeof(int);
    int n_right= sizeof(right)/sizeof(int);

    int i,j,k; i = j = k = 0;
    while(i<n_left && j<n_right){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n_left){
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j<n_right){
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[]){
    int n = sizeof(arr)/sizeof(int);
    if(n < 2){
        return;
    }
    int mid = n/2;
    int left[mid];
    int right[n - mid];
    for(int i=0; i<mid; i++){
        left[i] = arr[i];
    }
    for(int i=mid; i<n; i++){
        right[i-mid] = arr[i];
    }

    mergeSort(left);
    mergeSort(right);
    merge(arr, left, right);
}

int main(){

    int arr[] = {2, 7, 6, 5, 9, 14, 97};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }   
    cout << endl;
    mergeSort(arr);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}