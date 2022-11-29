#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> g;
int used[100];


void dfs(int v){
    used[v] = 1;
    g.push_back(v);

    if(g.size() == n+1){
        for(int i=1; i<=n; i++){
            cout << g[i] << " ";
        }
        cout << endl;
    }

    for(int i=1; i<=n; i++){
        if(used[i] == 0){
            dfs(i);
        }
    }

    used[v] = 0;
    g.pop_back();
}

int main(){
    cin >> n;
    dfs(0);
    return 0;
}