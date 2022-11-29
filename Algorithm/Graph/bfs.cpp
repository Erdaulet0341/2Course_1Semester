#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x, y;
vector<int> g[100];
queue<int> q;
int distanc[100];
int used[100];


void bfs(int ver){
    q.push(ver);
    distanc[ver] = 0;
    used[ver] = 1;
    while(!q.empty()){
        x = q.front();
        for(int i=0; i<g[x].size(); i++){
            y = g[x][i];
            if(used[y] == 0){
                q.push(y);
                used[y] = 1;
                distanc[y] = distanc[x]+1;
            }
        }
        q.pop();
    }
}


int main(){
    
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(6);
    for(int i=1; i<=n; i++){
        cout << i << " - " << distanc[i] << endl;
    }

}