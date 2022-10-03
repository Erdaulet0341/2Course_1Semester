#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int x, int last, int first){
    while(first<=last){
        int mid = first + (last - first) / 2;
        if(arr[mid]>x){
            last = mid-1;
        }
        else if(arr[mid] < x){
            first = mid+1;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int x; cin >> x;
    int first = 0, last = n-1;
    if(binarySearch(arr, x, last, first)){
        cout << "Yes";
    }
    else{cout << "No"; }
}