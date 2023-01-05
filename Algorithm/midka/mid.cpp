#include <bits/stdc++.h>
using namespace std;

vector<int> vt;
void primes(int n, bool a[]){
    for(int j = 0; j <= n; j++)a[j] = true;
    for(int j = 2; j*j <= n; j++){
        if(a[j]){
            for(int i = j*j; i <= n; i += j){
                a[i] = false;
            }
        }
    }
    a[0] = false;
    a[1] = false;
    a[2] = true;
    a[3] = true;
    // for(int i = 0; i <= n; i++ )cout << a[i] << ' ';
    for(int j = 2; j < n; j++){
        if(a[j])vt.push_back(j);
    }
}

int main(){
    int n;scanf("%d", &n);
    bool a[n+1];
    primes(n, a);
    for(int j = 0; j < vt.size(); j++){
        for(int i = 0; i < vt.size(); i++){
            if(vt[i] == n-vt[j]){cout << vt[j] << " "<< vt[i];return 0;}
        }
    }
    return 0;
}