#include <bits/stdc++.h>
using namespace std;

int n;


int main(){
    cin >> n;

    int graph[n][n];
    int used[n];


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    vector<bool> v(n, false);

    for(int i = 0; i < n; i++){
        cin >> used[i];used[i]--;
    }

    for(int k = 0; k < n; k++){
        int ans = 0;
        int o = used[k];
        v[o] = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                graph[i][j] = min(graph[i][j], graph[i][o] + graph[o][j]);
                if(v[j] and v[i]){
                    ans = max(ans, graph[i][j]);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}