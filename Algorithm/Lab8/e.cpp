#include <iostream>
using namespace std;

long long hash_(long long x, long long pow){
    return (x/pow+97);
}

string inHashToString(long long pre[], long long n){
    long long ans[n];
    long long pow=1, x;
    ans[0] = hash_(pre[0], pow);
    for(long long i=1; i<n; i++){
        pow*=2;
        x = pre[i] - pre[i-1]; // 15 - 7 = 8
        ans[i] = hash_(x, pow); // 8, 1
    } 

    string s="";

    for(long long i=0; i<n; i++){
        s+=char((ans[i]));
    }
    return s;
}

int main(){ 
    long long n;
    cin >> n;
    long long pre[n];
    for(long long i=0; i<n; i++){
        cin >> pre[i];
    }
    cout << inHashToString(pre, n);
    return 0;
}