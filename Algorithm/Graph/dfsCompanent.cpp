#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100];
int used[100];
int n, m, x, y;

void dfs(int v){
    used[v] = 1;
    for(int i=0; i<g[v].size(); i++){
        y = g[v][i];
        if(used[y] == 0){
            dfs(y);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(used[i] == 0){
            cnt++;
            dfs(1);
        }
    }
    cout <<cnt;
    return 0;
}