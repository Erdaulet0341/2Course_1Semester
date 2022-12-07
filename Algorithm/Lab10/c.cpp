#include <bits/stdc++.h>
using namespace std;

class gr{
    int V;
    map<int, vector<int>> arr;
    vector<int> l;

    public:
        gr(int V);

        int add(int v, int w, int l_cur);

        void bfs(int s);

        void sl(int a, int l_cur);

        void dfs(int begin, int end);
};

gr::gr(int V){
    this->V = V;
    l.resize(V, -1);
}

void gr::sl(int a, int l_cur){
    l[a] = l_cur;
}

int gr::add(int v, int w, int l_cur){
    if(l[w] == -1){
        arr[v].push_back(w);
        arr[w].push_back(v);
        l[w] = l_cur;
        return 1;
    } 
    return 0;
}

void gr::bfs(int s){
    vector <bool> used(V, false);

    queue<int> q;
    used[s] = true;
    q.push(s);
    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
            
            int x = q.front();
            q.pop();
            cout << x <<  ' ' << l[x] << endl;
            for(auto i: arr[x]){
                if(!used[i]){
                    used[i] = true;
                    q.push(i);
                }
            }
        }
    }
}

vector<int> p;
void gr::dfs(int begin, int end){
    p.push_back(begin);
    if(begin == end){
        return;
    }
    for(auto i: arr[begin]){
        if(l[i] == l[begin] - 1){
            dfs(i, end);
        }
    }
}

int main(){

    int a, b;
    cin >> a >> b;

    gr g(20000);

    queue<int> q;
    q.push(a);
    int l_cur = 1;
    g.sl(a, l_cur++);
    while(!q.empty()){
        int size = q.size();
        int stop = 0;
        for(int i = 0; i < size; i++){
            int x = q.front();
            q.pop();

            if(x == b){
                stop = 1;
                break;
            }
            if(x < b){
                if(g.add(x, 2 * x, l_cur) == 1){
                    q.push(2 * x);
                }
            }
            if(x - 1 > 0){
                if(g.add(x, x-1, l_cur) == 1){
                    q.push(x-1);
                }
            }
        }
        l_cur++;
        if(stop == 1){
            break;
        }
    }

    g.dfs(b, a);
    cout << p.size() - 1 << endl;
    for(int i = p.size() - 2; i >= 0; i--){
        cout << p[i] << ' ';
    }
}