#include <bits/stdc++.h>
using namespace std;

bool isTrue(int i, int j, int n, int m){
    return i >= 0 and i < n and j >= 0 and j < m;
}

int bfs(vector<vector<int> >& v, int n, int m, queue <pair<int, int> > q){
    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        for(int x = 0; x < size; x++){
            int i = q.front().first;
            int j = q.front().second;
            if(isTrue(i-1, j, n, m)){
                if(v[i-1][j] == 1){
                    v[i-1][j] = 2;
                    q.push(make_pair(i-1, j));
                }
            }
            if(isTrue(i+1, j, n, m)){
                if(v[i+1][j] == 1){
                    v[i+1][j] = 2;
                    q.push(make_pair(i+1, j));
                }
            }
            if(isTrue(i, j-1, n, m)){
                if(v[i][j-1] == 1){
                    v[i][j-1] = 2;
                    q.push(make_pair(i, j-1));
                }
            }
            if(isTrue(i, j+1, n, m)){
                if(v[i][j+1] == 1){
                    v[i][j+1] = 2;
                    q.push(make_pair(i, j+1));
                }
            }
            q.pop();
        }
        if(!q.empty()){
            cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 1){
                return -1;
            }
        }
    }
    return cnt;

}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > arr;
    queue <pair<int, int> > q;

    for(int i = 0; i < n; i++){
        vector<int> v;
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            v.push_back(x);
            if(v[j] == 2){
                q.push(make_pair(i, j));
            }
        }
        arr.push_back(v);
    }

    cout << bfs(arr, n, m, q);

}