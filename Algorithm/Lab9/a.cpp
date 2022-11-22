#include<bits/stdc++.h>
using namespace std;


vector<int> p_f(string s){
    int n = s.size();
    vector<int>pat(n);
    pat[0] = 0;

    for(int i = 1; i < n; i++){
        int j = pat[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pat[j - 1];

            if(s[i] == s[j]){
                j++;
            }
            pat[i] = j;
        }
    return pat;    
}

bool checkPattern(vector<int> v ,int size){
    for(int i=0; i<v.size(); i++){
        if(v[i] == size)
            return true;
    }
    return false;
}

int main(){
    string a,b;
    cin >> a >> b;
    string answer = a;
    int cnt = 1;
    while(answer.size() < b.size()){
        answer += a;
        cnt++;
    }
    
    if(checkPattern(p_f(b + '#' + answer),b.size())){
        cout << cnt;
    }
    else{
        if(checkPattern(p_f(b + '#' + answer + a),b.size()))
            cout << cnt + 1;
        else
            cout << -1;
    }


    return 0;
}