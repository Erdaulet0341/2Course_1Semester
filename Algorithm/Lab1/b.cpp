#include <bits/stdc++.h>
using namespace std;

int cl(vector<int> v, int x){
    if(v.size() == 0)return -1;
    for(int i = v.size()-1; i >= 0; i--){
        if(v[i] <= x)return v[i];
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v, ans;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ans.push_back(cl(v, x));
        v.push_back(x);
    }
    for(int x:ans)cout << x << ' ';
    return 0;
}