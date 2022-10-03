#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll X[200000], Y[200000];

bool is_pos(int cnt){
    return k == cnt;
}

int solve(ll N){
    ll l = 0, r = N;
    while(l+1 < r){
        int cnt = 0;
        int m = (r+l)/2;
        for(int i = 0; i < n; i++){
            if(m >= X[i] and m >= Y[i])cnt++;
        }
        (is_pos(cnt) or cnt > k? r : l) = m;
        // cnt = 0;
    }
    return r;
}
int main(){
    cin >> n >> k; 
    for(int i = 0; i < n; i++){
        ll x1, y1;
        cin >> x1 >> y1 >> X[i] >> Y[i];
    }

    cout << solve(1e9);
}