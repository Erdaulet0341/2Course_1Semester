#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int ptt(int arr[],int l, int r) {
    int pivot = arr[r];

    int i = (l-1);

    for(int j = l;j<r;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
void quickSort(int arr[], int l, int r) {
    if(l < r) {
        int pi = ptt(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main() {
    int n;cin>>n;
    int a[n+1];
    for(int i = 0;i < n;i++) {
        int x;cin>>x;
        a[i]=x;
    }
    quickSort(a,0,n-1);
    int absMin = 1e9;
    map<pair<int,int>,int> mp;
    for(int i = 1;i < n;i++) {
        int dif = a[i]-a[i-1];
        if(absMin>dif) absMin = dif;
        mp[make_pair(a[i],a[i-1])] = dif;
    }
    for(map<pair<int,int>, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        if(it->second == absMin){
            cout << it->first.second << ' ' << it->first.first << ' ';
        }
    }
}