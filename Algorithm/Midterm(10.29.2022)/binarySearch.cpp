#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int x){
    int first = 0;
    int last = n-1;
    while(first<=last){
        int middle = first + (last-first)/2;
        if(arr[middle]>x){
            last = middle-1;
        }
        else if(arr[middle]<x){
            first = middle+1;
        }
        else{
            return middle;
        }
    }
    return -1;
}

int binarySearchReverse(int arr[], int n, int x){
    int first = 0; 
    int last = n-1;
    while(first<=last){
        int m = first+(last-first)/2;
        if(arr[m]>x){
            first = m +1;
        }
        else if(arr[m]<x){
            last = m - 1;
        }
        else{
            return m;
        }
    }
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr2[m];
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int re[n];
    for(int i=n-1, j=0; j<n, i>=0;j++, i--){
        re[j] = arr[i];
    }
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }
    for(int i=0; i<m; i++){
        if(binarySearch(arr, n, arr2[i])!=-1)
            cout << binarySearch(arr, n, arr2[i])+1 << " " << binarySearch(re, n, arr2[i])+1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}