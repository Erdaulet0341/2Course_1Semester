#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100];
int used[100];
int x, y, n, m;
bool ok = true;
void dfs(int v, int c){
    used[v] = c;
    for(int i=0; i<g[v].size(); i++){
        if(used[g[v][i]]  == 0){
            if(c == 1){
                dfs(g[v][i], 2);
            }
            else dfs(g[v][i], 2);
        }
        if (used[g[v][i]] == c){
            ok = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        g[y].push_back(x);
        g[x].push_back(y);
    }
    dfs(1, 1);
    cout << ok;
} 
