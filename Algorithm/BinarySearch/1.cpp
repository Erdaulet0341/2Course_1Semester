#include <iostream>
using namespace std;

int bs(int a[], int n, int x){
    int l = 0, r = n-1, m;
    while(l<=r){
        m = l + (r-l)/2;
        if(a[m]<x){
            l = m+1;
        }
        else if(a[m]>x){
            r = m-1;
        }
        else{
            return m;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int x; cin >> x;
    cout << bs(arr, n, x);
}