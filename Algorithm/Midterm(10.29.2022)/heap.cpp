#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        pq.push(x);
    }

    int x; cin>> x;
    pq.push(x);
    int cnt=0;
    while(!pq.empty()){
        if(pq.top()==x){
            cout << cnt+1;
        }
        pq.pop();
        cnt++;
    }

}