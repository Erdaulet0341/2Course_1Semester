#include <bits/stdc++.h>
using namespace std;
#define longg long long

const longg mod = 1e9 + 7;
const int p = 11;
vector <longg> hs;
vector <bool> saw;

longg hashh(string s){
    longg h = 1, res = 0;
    for(int i = 0; i < s.size(); i++){
        res = (res + (s[i] - 'a' + 1) * h) % mod;
        h = (h * p) % mod;
    }
    return res;
}

void prefix(string s){
    hs.resize(s.size()); longg h = 1;
    saw.resize(s.size());
    for(int i = 0; i < s.size(); i++){
        hs[i] = (s[i] - 'a' + 1) * h % mod;
        if(i) hs[i] = (hs[i] + hs[i-1]) % mod;
        h = (p * h) % mod;
    }
}

void RBK(string s, string pattern){
    longg res = 0, h = 1;
    for(int i = 0; i < pattern.size(); i++){
        res = (res + (pattern[i] - 'a' + 1) * h) % mod;
        h = (h * p) % mod;
    }
    longg ssub_match = hashh(pattern);
    for(int i = 0; i < s.size() - pattern.size() + 1; i++){
        longg b_h = hs[i + pattern.size() - 1];
        if(i) b_h -= hs[i-1];
        if(b_h < 0) b_h += mod;
        if(i) ssub_match = (ssub_match * p) % mod;
        if(ssub_match == b_h){
            for(int pll = i; pll < i + pattern.size(); pll++){
                saw[pll] = true;
            }
        }
    }
}

int main(){
    string s; cin >> s;
    prefix(s);
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        string text; cin >> text;
        RBK(s, text);
    }

    for(int i = 0; i < s.size(); i++){
        if(!saw[i]){
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES";
}