#include <bits/stdc++.h>
using namespace std;

vector<int> g[5001];
bool used[5001];
int d[5001];
int color[5001];
int n;

void bfs(int s) {
    for (int i = 1; i <= n; i++) {
        used[i] = 0;
    }
    queue<int> q;
    q.push(s);
    d[s] = 0;
    used[s] = 1;
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        for (int i = 0; i < g[y].size(); i++) {
            int x = g[y][i];
            if (d[x] > d[y] + 1) {
                d[x] = d[y] + 1;
                used[x] = 1;
                q.push(x);
            }
        }
    }
}

int main() {
    int m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }

    for (int t = 1; t <= q; t++) {
        int type, y;
        cin >> type >> y;
        if (type == 1) {
            if (color[y] != 1) {
                bfs(y);
                color[y] = 1;
            }
        } else {
            if (d[y] == 1e9) {
                cout << -1 << endl;
            } else {
                cout << d[y] << endl;
            }
        }
    }

    return 0;
}