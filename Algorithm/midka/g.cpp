#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> v, a;
    v.push_back(0);
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        v.push_back(x);
    }
    for(int i = 1; i < n+1; i++){
        a.push_back(v[i]-v[i-1]);
    }

    for(int i = 0; i < n; i++){
        int sum = 0, cnt = 0;
        for(int j = i; j >= 0; j--){
            if(sum > 3000)break;
            sum += a[j];
            cnt++;
        }
        cout << cnt << ' ';
    }

}