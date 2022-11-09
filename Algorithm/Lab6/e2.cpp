#include <iostream>
using namespace std;

void merger(int arr[], int l, int m, int r){
    int nl = m - l +1;
    int nr = r-m;

    int arr_l[nl], arr_r[nr];
    for(int i=0; i<nl; i++){
        arr_l[i] = arr[i+l];
    }
    for(int i=0; i<nr; i++){
        arr_r[i] = arr[i+m+1];
    }

    int il=0, ir=0, ia=l;

    while(il<nl && ir<nr){
        if(arr_l[il] <= arr_r[ir]){
            arr[ia] = arr_l[il];
            il++;
        }
        else{
            arr[ia] = arr_r[ir];
            ir++;
        }
        ia++;
    }

    while(il<nl){
        arr[ia] = arr_l[il];
        il++; ia++;
    }
    while(ir<nr){
        arr[ia] = arr_r[ir];
        ia++; ir++;
    }
}
void merge_sort(int arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merger(arr, l, m, r);
    }
}

int main() {
    int n,m;cin>>n>>m;
    int a[n+1][m+1];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin>>a[i][j];
        }
    }

    for(int i = 0;i < m;i++) {
        int newArr[n];
        for(int j = 0;j < n;j++) {
            newArr[j] = a[j][i];
        }
        merge_sort(newArr,0,n-1);
        for(int j = 0;j < n;j++) {
            a[j][i] = newArr[n-1-j]; 
        }
    }
    
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << a[i][j] << " ";
        }cout << '\n';
    }
}