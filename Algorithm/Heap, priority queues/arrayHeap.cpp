#include <bits/stdc++.h>
using namespace std;

void heap_down(int a[], int i, int n){

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int min_pos = i;
    if(l<n && a[min_pos]>a[l]) min_pos=l;
    if(r<n && a[min_pos]>a[r]) min_pos=r;

    if(i!=min_pos){
        swap(a[i], a[min_pos]);
        heap_down(a, min_pos, n);
    }
}

int cut_min(int a[], int n){
    int res = a[0];
    a[0] = a[n-1];
    heap_down(a, 0, n-1);
    return res;
}

int main(){
    int a[] = {9,5,6,3};
    int n = sizeof(a)/sizeof(int);

    cout << cut_min(a, n) << endl;
    cout << cut_min(a, n-1) << endl;
    cout << cut_min(a, n-2) << endl;

    return 0;
}