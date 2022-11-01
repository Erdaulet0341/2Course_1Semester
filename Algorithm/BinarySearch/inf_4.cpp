#include <iostream>
using namespace std;

bool check(int arr[], int x, int n){
    int l = 0, r = n-1, m;
    while(l<=r){
        m = l+(r-l)/2;
        if(arr[m]<x){
            l = m+1;
        }
        else if(arr[m]>x){
            r = m-1;
        }
        else {
            return true;
        }
    }
    return false;

}

int main(){
    int n, m;
    cin >> n >> m;
    int ar1[n], ar2[m];
    for(int i=0; i<n; i++){
        cin >> ar1[i];
    }
    for(int i=0; i<m; i++){
        cin >> ar2[i];
    }
    for(int i=0; i<m; i++){
        if(check(ar1, ar2[i], n)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;  
}