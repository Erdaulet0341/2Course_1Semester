#include <bits/stdc++.h>
using namespace std;

void pr(deque<int> st){
    for(deque<int> dumb = st; not dumb.empty(); dumb.pop_front()){
        cout << dumb.front() << ' ';
    }
    cout << endl;


}
int main(){
    vector<int> b , n;
    for(int i = 0; i < 5; i++){
        int x; cin >> x;
        b.push_back(x);
    }
     for(int i = 0; i < 5; i++){
        int x; cin >> x;
        n.push_back(x);
    }
    int cnt = 0;
    while(not b.empty() and not n.empty()){
        int bb = b[0], nb = n[0];
        if(bb > nb){
            if(bb == 9 and nb == 0){
                n.push_back(bb);
                n.push_back(nb);
            }else{
                b.push_back(bb);
                b.push_back(nb);      
            }
        }else{
            if(nb == 9 and bb == 0){
                b.push_back(bb);
                b.push_back(nb);
            }else{
                n.push_back(bb);
                n.push_back(nb);      
            }
        }

        b.erase(b.begin());n.erase(n.begin());
        cnt++;
        if(cnt == 1000000){
            cout << "blin nichya";
            return 0;
        }
    }


    string res = b.empty() ? "Nursik" : "Boris";
    cout << res << ' ' << cnt;



    return 0;
}
