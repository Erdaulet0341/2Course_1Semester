#include <bits/stdc++.h>

#define inf 1000500
#define INF (1ll<<50)
using namespace std;

long long n, m, a, b, c, x;
pair<long long,long long> arraya[inf];
long long dxtr[inf];
bool q[inf];

long long dijk(long long s, long long f){
    fill(dxtr, dxtr+n, INF);
    fill(q, q+n, 0);
    dxtr[s] = 0;
    for(int i = 0; i < n; i++){
        long long v = -1;
        for(int j = 0; j < n; j++) if (!q[j] && (v == -1 || dxtr[j] < dxtr[v])) v = j;
        if (v == -1 || dxtr[v] == INF) break;
        q[v] = true;
        for(int j = 0; j < n; j++){
            long long by = j, length = abs(arraya[j].first - arraya[v].first) + abs(arraya[j].second - arraya[v].second);
            dxtr[by] = min(dxtr[by], max(dxtr[v], length));
        }
    }
    return dxtr[f];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arraya[i].first >> arraya[i].second;
    }
    cout << dijk(0, n-1);
    return 0;
}