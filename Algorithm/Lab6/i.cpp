#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    string s;
    cin >> s;
    vector<char> v1;
    for (int i=0; i<s.length(); i++){
        v1.push_back(s[i]);
    }
    sort(v1.begin(), v1.end());
    for (int i=0; i<v1.size(); i++){
        cout << v1[i];
    }

}