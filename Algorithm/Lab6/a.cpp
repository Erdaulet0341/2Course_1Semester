#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v1;
    vector<char> v2;

    for (int i=0; i<n; i++){
        char c = s[i];
        if(c == 'a' || c=='e' || c=='i' || c=='u' || c=='o'){
            v1.push_back(c);
        }
        else{
            v2.push_back(c);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i=0; i<v1.size(); i++){
        cout << v1[i];
    }
    for (int i=0; i<v2.size(); i++){
        cout << v2[i];
    }

}