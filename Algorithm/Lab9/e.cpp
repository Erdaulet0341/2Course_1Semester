#include <iostream>
#include <vector>
using namespace std;

vector <int> pre;

vector <int> pref_fun(string s){
    pre.resize(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = pre[i-1];
        while(j > 0 && s[i] != s[j]) j = pre[j-1];
        if(s[i] == s[j]) j++;
        pre[i] = j;
    }
    return pre;
}
int main(){
    int n, t; 
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s >> t;
        vector<int> result = pref_fun(s);
        int res = s.size() - result.back();
        cout << res * (t - 1) + s.size() << endl;
    }
}