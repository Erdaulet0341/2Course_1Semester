#include <bits/stdc++.h>
using namespace std;

void putBack(vector<int>& v){
    int tmp = v[v.size()-1];
    v.pop_back();
    v.insert(v.begin(), tmp);
    

}

int main(){
    int t;cin >> t;

    while(t--){
        vector<int> v;
        int x;cin >> x;
        for(int i = x; i > 0; i--){
                v.insert(v.begin(), i);
                for(int j = 0; j < i; j++){
                    putBack(v);
                }
            
        }
        for(int k:v)cout << k << ' ';
        cout << endl;
        
    }

    return 0;
}