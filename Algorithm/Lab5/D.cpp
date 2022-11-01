#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    priority_queue<int, vector<int>, greater<int>> pq;
    scanf("%d%d", &n, &t);
    while(n--){
        int x;scanf("%d", &x);
        pq.push(x);
    }

    int o = 0;
    while(true){
        if(pq.top() >= t)break;
        if(pq.size() < 2){cout << -1;return 0;}
        int l = pq.top();pq.pop();
        int l2 = pq.top();pq.pop();
        pq.push(l + 2*l2);
        o++;
    }  

    cout << o;
    return 0;
}