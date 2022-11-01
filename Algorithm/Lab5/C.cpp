#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    priority_queue<int> pq;
    while(n--){
        int x;scanf("%d", &x);
        pq.push(x);
    }
    long long result = 0;
    while(x--){
        int mx = pq.top();
        pq.pop();
        if(mx == 0)break;
        result += mx;
        pq.push(mx-1);
    }

    cout << result;
    return 0;
}