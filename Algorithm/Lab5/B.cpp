#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

int solve(vector<int> &v){
    priority_queue<int> pq(begin(v), end(v));
    while(pq.size() > 1){
        int x = pq.top();pq.pop();
        int y = pq.top();pq.pop();
        if(x > y)pq.push(x-y);
    }

    return pq.empty() ? 0 : pq.top();
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;scanf("%d", &x);
        a.push_back(x);
    }

    cout << solve(a);
}