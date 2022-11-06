#include <iostream>
#include <algorithm>
using namespace std;

void swap(int * a, int * b){
    int t=*a;
    *a = *b;
    *b=t;
}

int par(int arr[],int l,int r){
    int p=arr[r];
    int i=(l-1);
    for(int j=l;j<r;j++){
        if(arr[j]<p){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}

void quick_sort(int arr[],int l,int r){
    if(l<r){
        int pi=par(arr,l,r);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,r);
    }
}

bool binary_Search(int arr[], int l, int r, int x){
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] == x){
            return true;
        }
        if(arr[mid] < x){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return false;
}

int main() {
    int m, n; cin >> m >> n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }


    quick_sort(arr,0,n-1);


    for(int i = 0; i < n ; i++){
        if(binary_Search(arr,0,n-1, m-arr[i])){
            cout << arr[i] << " " << m - arr[i];
            return 0;
        }
    }

}