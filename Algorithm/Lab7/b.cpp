#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Merge(int arr[], int left, int m, int right){
    int n_left = m - left + 1;
    int n_right = right - m;

    int arr_left[n_left], arr_right[n_right];

    for(int i=0; i<n_left; i++){
        arr_left[i] = arr[left + i];
    }
    for(int i=0; i<n_right; i++){
        arr_right[i] = arr[m + 1 + i];
    }

    int i_left, i_right, i_v;
    i_left = i_right = 0; i_v = left;

    while(i_left < n_left && i_right < n_right){
        if(arr_left[i_left] <= arr_right[i_right]){
            arr[i_v] = arr_left[i_left];
            i_left++;
        }
        else{
            arr[i_v] = arr_right[i_right];
            i_right++;
        }
        i_v++;
    }

    while(i_left<n_left){
        arr[i_v] = arr_left[i_left];
        i_left++; i_v++;
    }

    while(i_right < n_right){
        arr[i_v] = arr_right[i_right];
        i_right++; i_v++;
    }

}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid =left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        Merge(arr, left, mid, right);
    }
}


int main(){
    int n;
    cin >> n;
    int arrn[n];
    for (int i=0; i<n; i++){
        cin >> arrn[i];

    }
    
    int n2;
    cin >> n2;
    int arrn2[n2];
    for (int i=0; i<n2; i++){
        cin >> arrn2[i];
    }
    int arr[n+n2];
    int iarr = 0;
    for(int i=0; i<n; i++){
        arr[iarr] = arrn[i];
        iarr++;
    }
    for(int i=0; i<n2; i++){
        arr[iarr] = arrn2[i];
        iarr++;
    }
    mergeSort(arr, 0, n+n2-1);

    for(int i=0; i<n+n2; i++){
        cout << arr[i] << " ";
    }
}