#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    vector<int> v;
    for(int i; i<t; i++){
        int k; cin >> k;
        v.push_back(k);
    }
    int n, m; cin >> n>> m;
    int arr[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0; i<t; i++){
        for (int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(v[i]==arr[j][k]){
                    cout << j << " " << k << "\n";
                    j = n-1;
                    k = m-1;
                }
                else if(j==n-1 && k == m-1){
                    cout << -1 << "\n";
                }
            }
        }
    }
}