#include <bits/stdc++.h>
using namespace std;

#define ten_ten 100000000
#define f first
#define s second

int n, m, a, b;

vector<vector<pair<int, int>>> graph(200500);

vector<int> dist(int s){
    vector<int> d(n, ten_ten);
    priority_queue<pair<int, int>> q;
    d[s] = 0;
    q.push({0, s});
    while(!q.empty()){
        int u = q.top().s, dist = -q.top().f;
        q.pop();
        if(dist > d[u])continue;

        for(int i = 0; i < graph[u].size(); i++){
            int sec = graph[u][i].f, len = graph[u][i].s;
            if(d[u]+len < d[sec]){
                d[sec] = d[u]+len;
                q.push({-d[sec], sec});
            }
        }
    }
    return d;
}


int main(){
    int s, f1;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--;v--;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    cin >> s >> a >> b >> f1;
    s--;a--;b--;f1--;

    vector<int> sv = dist(s), av = dist(a), bv = dist(b);
    long long ans = INT_MAX; 
    long long r1 = sv[a] + av[b] + bv[f1];
    long long r2 = sv[b] + bv[a] + av[f1];
    long long r3 = sv[a] + av[s] + sv[b] + bv[f1];
    long long r4 = sv[b] + bv[s] + sv[a] + av[f1];
    long long r5 = sv[a] + av[b] + bv[s] + sv[f1];
    long long r6 = sv[a] + av[b] + bv[a] + av[f1];
    long long r7 = sv[a] + av[b] + bv[a] + av[s] + sv[f1];
    long long r8 = sv[b] + bv[a] + av[s] + sv[f1];
    long long r9 = sv[b] + bv[a] + av[b] + bv[s] + sv[f1];


    if(bv[a] == ten_ten and bv[s] == ten_ten){cout << -1;return 0;}
    if(av[s] == ten_ten and av[b] == ten_ten){cout << -1;return 0;}
    if(sv[f1] == ten_ten and av[f1] == ten_ten and bv[f1] == ten_ten){cout << -1;return 0;}

    ans = min(r1, min(r2, min(r3, min(r4, min(r5, min(r6, min(r7, min(r8, r9))))))));

    cout << ans;
    return 0;
}