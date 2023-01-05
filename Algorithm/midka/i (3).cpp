#include <bits/stdc++.h>
using namespace std;

string tos(long long x){
    string t = "", s = "";
    while(x){
        t += x%2 + '0';
        x /= 2;
    }

    for(int i = t.size()-1; i >= 0; i--)s += t[i];

    return s;
}

int main(){
    int n;cin >> n;
    while(n--){
        stack<char> st; 
        long long x;cin >> x;
        string t = tos(x);
        // cout << s << endl;
        for(int i = 0; i < t.size(); i++){
            if(st.empty())st.push(t[i]);
            else{
                if(st.top() == '1' and t[i] == '0')st.pop();
                else st.push(t[i]);
            }
        }
        if(st.empty())cout << "YES\n";
        else cout << "NO\n";
    }

}