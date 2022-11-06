#include <iostream>
using namespace std;

void merge(int arr[], int left, int m, int right){
    int nl = m - left + 1; 
    int nr = right - m;

    int l[nl], r[nr];

    for(int i=0; i<nl; i++){
        l[i] = arr[left+i];
    }
    for(int i=0; i<nr; i++){
        r[i] = arr[i+m+1];
    }

    int li, ri, ai=left; li = ri = 0;
    while(li<nl && ri<nr){
        if(l[li] <= r[ri]){
            arr[ai] = l[li];
            li++;
        }
        else{
            arr[ai] = r[ri];
            ri++;
        }
        ai++;
    }

    while(li<nl){
        arr[ai] = l[li];
        ai++;
        li++;
    }

    while(ri<nr){
        arr[ai] = r[ri];
        ri++;
        ai++;
    }

}

void merge_sort(int arr[], int left, int right){
    if(left<right){
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}