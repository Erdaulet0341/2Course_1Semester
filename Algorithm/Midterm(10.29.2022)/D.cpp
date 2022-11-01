#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long zer[n+1];

    for(long long i=0; i<n+1; i++){
        zer[i] = 0;
    }
    
    for(long long i=2; i*i<=n; i++){
        if(zer[i]==0){
            int k = i;
            while(k<=n){
                k+=i;
                zer[k]=1;
            }
        }
    }

    long long cnt=0;

    for(long long i=2; i<=n/2; i++){
        if(zer[i]==0){
            if(n%i==0){
                cnt++;
            }
        }
    }

    cout << cnt;
}