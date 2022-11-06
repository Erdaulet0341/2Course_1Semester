#include <iostream>
#include <algorithm>
using namespace std;

string to_binary(long long n){
    if(n==0){
        return "";
    }
    if(n%2==0){
        return to_binary(n/2) + '0';
    }
    else{
        return to_binary((n-1)/2) + '1';
    }
}

string check(string s){
    long long cnt=0;
    for(long long i=0; i<s.length(); i++){
        if(s[i]=='1') 
            cnt++;
        else if(cnt>0) 
            cnt--;
        else
            return "NO";
    }
    if(cnt == 0) return "YES";
    else return "NO";
}

int main(){
    long long n;
    cin >> n;
    string arr[n];
    int i=0;
    for(long long i=0; i<n; i++){
        long long x; cin >> x;
        arr[i] =(check(to_binary(x)));
    }

    for(long long i=0; i<n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}