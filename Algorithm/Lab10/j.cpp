#include <bits/stdc++.h>
using namespace std;

class gr{
    int V;
    vector<pair<list<int>, int>> d;    
    vector<bool> used;

    public:
        gr(int V);

        void add(int x, int y);

        void bfs();
};

gr::gr(int V){
    this->V = V;
    d.resize(V);
    used.resize(V, false);
}

void gr::add(int x, int y){
    d[x].first.push_back(y);
    d[x].second = 0;
}

int cnt = 0;

void gr::bfs(){
    for(int i = 0; i < V; i++){
        if(!used[i]){
            int ans = 0;
            queue <int> q;
            q.push(i);

            used[i] = true;

            while(!q.empty()){
                int size = q.size();
                for(int j = 0; j < size; j++){
                    int x = q.front();
                    q.pop();

                    for(auto i: d[x].first){
                        if(!used[i]){
                            used[i] = true;
                            q.push(i);
                            d[i].second = d[x].first.size();
                        }
                    }
                    if(d[x].first.size() > d[x].second){
                        cnt++;
                    }
                }
                ans++;
            }
            if(ans == 1){
                cnt++;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    gr g(n);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g.add(x-1, y-1);
    }
    
    g.bfs();

    cout << cnt;

    return 0;
}