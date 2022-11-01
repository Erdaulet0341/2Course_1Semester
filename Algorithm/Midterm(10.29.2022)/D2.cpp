#include <iostream>
#include <set>
using namespace std;

int count(long long n){ // 1000
    set<long long> s;
    long long c=2;
    while(n>1) // 1000 
    {
        if(n%c==0){ //1000%2==0, 500%5==0, 100%6==, 
            s.insert(c); // s = 2,5
            n/=c; // 500, 100, 
        }
        else c++;
    }
    return  s.size();
}

int main(){
    long long n;
    cin >> n;
    cout << count(n);
}