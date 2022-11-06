#include <bits/stdc++.h>
using namespace std;

struct Solution{
private:
    vector<pair<int, int> > v;
public:

    void add(int x){
        if(v.empty()) 
            v.push_back( make_pair(x, x)); //make_pair(arr[i],arr1[i])
        else 
            v.push_back( make_pair(x, max(x, v.back().second)));
    }

    void deletee(){
        if(!v.empty()) v.pop_back();
    }

    int current(){
        if(v.empty()) return 0;
        return v.back().first;
    }

    int Max(){
        if(v.empty()) return 0;
        return v.back().second;
    }

    bool Empty(){
        if(v.empty()) return true;
        return false;
    }
};

int main(){

    int n;
    cin >> n; 
    int x, y;
    string s;
    Solution sl;

    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "add"){
            cin >> x;
            sl.add(x);
        }

        if(s == "delete"){
            sl.deletee();
        }

        if(s == "getcur"){
            if(sl.Empty()){
                cout << "error" << endl;
            }
            else{
                cout << sl.current() << endl;
            }
        }

        if(s == "getmax"){
            if(sl.Empty()){
                cout << "error" << endl;
            }
            else{
                cout << sl.Max() << endl;
            }
        }
    }
}
