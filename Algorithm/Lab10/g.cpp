#include <bits/stdc++.h>
using namespace std;

vector<int> graph[501];
int used[501];
stack<int> st;
vector<int> ans;

bool dfs(int y, int a, int b) {
    used[y] = 1;
    for (int i = 0; i < graph[y].size(); i++) {
        int x1 = graph[y][i];
        if (y == a && b == x1) continue;
        if (!used[x1]) {
            if (dfs(x1, a, b)) return true;
        } else if (used[x1] == 1) {
            return true;
        }
    }
    used[y] = 2;
    return false;
}

bool dfs_2(int y) {
    used[y] = 1;
    st.push(y);
    for (int i = 0; i < graph[y].size(); i++) {
        int x1 = graph[y][i];
        if (!used[x1]) {
            if (dfs_2(x1)) return true;
        } else if (used[x1] == 1) {
            while (st.top() != x1) {
                ans.push_back(st.top());
                st.pop();
            }
            ans.push_back(x1);
            ans.push_back(y);
            reverse(ans.begin(), ans.end());
            return true;
        }
    }
    used[y] = 2;
    if (!st.empty()) st.pop();
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }

    bool isTrue = false;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            isTrue = dfs_2(i);
            if (isTrue) break;
        }
    }
    
    if (!isTrue) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < ans.size() - 1; i++) {
        int x = ans[i];
        int y = ans[i + 1];
        for (int j = 1; j <= n; j++) {
            used[j] = 0;
        }
        isTrue = 0;
        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                isTrue |= dfs(j, x, y);
            }
        }
        if (!isTrue) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}