#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    string t;cin >> t;
    queue<int> s, k;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == 'S')s.push(i);
        else k.push(i);
    }

    while(not s.empty() and not k.empty()){
        if(s.front() < k.front())s.push(s.front() + n);
        else k.push(k.front() + n);
        s.pop();k.pop();
    }

    string ans = s.empty() ? "KATSURAGI" : "SAKAYANAGI";
    
    cout << ans;

    return 0;
}