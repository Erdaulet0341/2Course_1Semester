#include <bits/stdc++.h>
using namespace std;

    int a[1000000];
    
    int l = 0;

    void add(int x){
        a[++l] = x;
    }

    void del(){
        if(l != 0){ 
            l--;
        }
    }

    void getcur(){
        if(l == 0)cout << "error\n";
        else
            cout << a[l] << "\n";
    }

    void getmax(){
        if(l == 0)cout << "error\n";
        else{
            int mn = 0;
            for(int i = 0; i <= l; i++){
                mn = max(mn, a[i]);
            }
            cout << mn << "\n";
        }
    }



int main(){
    int n;cin >> n;
    while(n--){
        string s;cin >> s;
        if(s == "add"){
            int x;cin >> x;
            add(x);
        }else if(s == "delete"){
            del();
        }else if(s == "getmax"){
            getmax();
        }else getcur();
    }

    return 0;
}