#include <bits/stdc++.h>
using namespace std;

vector<int> prefix;


vector<int> pre_fun(string s) {
    prefix.resize(s.size());
  for (int i = 1; i < s.length(); i++){
    int j = prefix[i - 1];
    while (j > 0 && s[i] != s[j]) j = prefix[j - 1];
    if (s[i] == s[j]) j++;
    prefix[i] = j;
  }
  return prefix;
}

int main() {
  string s;
  cin >> s;
  vector<int> v = pre_fun(s);
  cout << s.size() - v.back();
}