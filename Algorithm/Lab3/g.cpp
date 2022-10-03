#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MAXN = 100000;
ll n, k;
bool is_pos(ll m, ll ar[]){ 
    ll sum = 0; 
    for(int i = 0; i < n; i++) sum += (ar[i] + m - 1)/m; 
    return sum <= k; 
} 
 
ll minbin_search(ll n, ll ar[]){ 
    ll l = 0, r = n; 
    while(r > l+1){ 
        ll m = (l+r)/2; 
        (is_pos(m, ar) ? r : l) = m; 
    } 
    return r; 
} 
 
int main(){ 
    cin >> n >> k;
    ll  ar[n];
    ll mx = 0;
    for(int i = 0; i < n; i++) {cin >> ar[i];mx = max(mx, ar[i]);}
    cout << minbin_search(10000, ar); 
    return 0; 
}