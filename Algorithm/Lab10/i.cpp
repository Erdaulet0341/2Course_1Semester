#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> arr; 
vector <int> isTrue;

vector <int> ans (queue <int> q, vector <bool> check){
    vector <int> answ;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        check[cur] = true;
        answ.push_back(cur);
        for(auto it: arr[cur]){
            if(not check[it]){
                isTrue[it]--;
                if(isTrue[it] == 0){
                    q.push(it);
                }
            }
        }



    }
    return answ; 
}

int main(){
    int n, m;
    cin >> n >> m;

    arr.assign(n + 1, vector <int> ());
    isTrue.assign( n + 1, 0);

    while(m --){
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        isTrue[y]++;
    }

    queue <int> q;

    for(int i = 1; i <= n; i++){
        if(isTrue[i] == 0){
            q.push(i);
        }
    }

    vector <bool> check(n + 1, 0);
    vector <int> v = ans(q, check);

    if(v.size() < n){
        cout << "Impossible" << endl;
    }
    else {
        cout << "Possible" << endl;
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
    }

    
    return 0;
}