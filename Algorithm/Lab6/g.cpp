#include <iostream>
#include <map>
using namespace std; 

bool check(map<string, string> mp, string s){
    for(map<string, string>::iterator it=mp.begin(); it!=mp.end(); it++){
        if(it->second == s){
            return true;
        }
    }
    return false;
}

string findNick(map<string, string> mp, string s){
    for(map<string, string>::iterator it=mp.begin(); it!=mp.end(); it++){
        if(it->second == s){
            return it->first;
        }
    }
}

int main(){
    int n; cin>> n;
    map<string, string> mp;
    string name, nickname;
    for(int i=0; i<n; i++){
        cin >> name >> nickname;
        if(check(mp, name)){
            mp[findNick(mp, name)] = nickname;
        }
        else{
            mp[name]=nickname;
        }
    }
    cout << mp.size() << endl;
    for(map<string, string>::iterator it=mp.begin(); it!=mp.end(); it++){
        cout << it->first << " " <<it->second << endl; 
    } 

    return 0;
}