#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<int, int> mk;
vector<int> vt;
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x;cin >> x;
        vt.push_back(x);
        mk[x] = i;
    }

    for(int i = 0; i < m; i++){
        int t = n - vt[i];
        if(mk[t] != 0 and mk[t] != i){
            cout << min(vt[i], t) << ' ' << max(vt[i],t);
            return 0;
        }
    }


}