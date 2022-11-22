#include <bits/stdc++.h>
using namespace std;

vector <int> pat(string s){
  int n = s.size();
  vector <int> v(n);
  v[0] = 0;

  for(int i=1; i<n; i++){
    int j = v[i-1];
    while(j > 0 && s[i] != s[j])
      j = v[j-1];

    if(s[i] == s[j])
      j++;

    v[i] = j;
  }
  return v;
}

int main(){
  string s, t;
  cin >> s >> t;

  vector <int> v = pat(s + '#' + t + t);
  bool check = false;
  for(int i=0; i<v.size(); i++){
    if(s.size() == v[i]){
      check = true;
      cout << i - 2 * s.size();
    }
  }

  if(!check)
    cout << -1;
}