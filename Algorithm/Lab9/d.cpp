#include <bits/stdc++.h>
using namespace std;

vector <int> pre;
vector <int> pre_fun(string s){
    pre.resize(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = pre[i - 1];
        while(j > 0 && s[i] != s[j]) j = pre[j - 1];
        if(s[i] == s[j]) j++;
        pre[i] = j;
    }
    return pre;
}


int main(){
    string s; 
    cin >> s;

    s[0] = tolower(s[0]);
    int n, m_f = 0; cin >> n;

    vector <pair<string, int> > prefix;  

    for(int i = 0; i < n; i++){
        string str; cin >> str;
        str[0] = tolower(str[0]);
        string join = str + s;
        vector <int> pref = pre_fun(join);
        m_f = max(m_f, pref.back());
        prefix.push_back({str, pref.back()});
    }

    vector <string> answer;

    for(auto i : prefix){
        if(i.second == m_f && m_f != 0){
            answer.push_back(i.first);
        }
    }
    
    cout << answer.size() << endl;

    for(int i = 0; i < answer.size(); i++){
        answer[i][0] = toupper(answer[i][0]);
        cout << answer[i] << endl;
    }



    return 0;
}