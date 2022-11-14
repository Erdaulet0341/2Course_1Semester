#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s1, s2, t;
    cin >> s1 >> s2 >> t; // qa
    int n = t.size();
    vector<string> v1;
    vector<string> v2;
    for(int i=0; i<=s1.size()-n; i++){ // qazaq 
        string x = s1.substr(i, n);
        v1.push_back(x);
    }
    for(int i=0; i<=s2.size()-n; i++){ // qazaq 
        string x = s2.substr(i, n);
        v2.push_back(x);
    }
    int cnt=0;
    for(int i=0; i<v2.size(); i++){
        
    }
    cout << cnt;
    return 0;
}