#include <bits/stdc++.h>
using namespace std;

vector <int> pref;

int pre_fun(string s) {
	int cnt = 0;
	pref.resize(s.size());

	for (int i = 1; i < s.length() - 1; i++) {
		int j = pref[i - 1];
		while (j > 0 && s[i] != s[j]) j = pref[j - 1];
		if (s[i] == s[j]) pref[i] = j + 1;
		if((i + 1) % (i + 1 - pref[i]) == 0 && (i + 1)/(i + 1 - pref[i]) % 2 == 0){ 
            cnt++; 
        } 
	}

	return cnt;
}

int main() {
	string s; 
    cin >> s;


	cout << pre_fun(s);
}