#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string to_binary(int n){
    string s = "";
    while(n>0){
        int x = n%2;
        char c = x + '0';
        s+=c;
        n/=2;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool check(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(st.empty())
            st.push(s[i]);
        else{
            if(s[i]=='0' and st.top() == '1'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    if(st.empty()) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int x; cin >> x;
        if(x==0){
            cout << "NO" << endl;
        }
        else{
            if(check(to_binary(x))) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}