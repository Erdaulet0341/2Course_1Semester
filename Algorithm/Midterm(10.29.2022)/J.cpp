#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long m;
    cin >> m;
    long long n; 
    cin >> n;
    long long arr[n];

    for(long long i=0; i<n; i++){
        cin >> arr[i];
    }

    for(long long i=0; i<n; i++){
        for(long long j=i; j<n; j++){
            if((arr[i]+arr[j])==m){
                cout << min(arr[i], arr[j]) << " " << max(arr[i], arr[j]);
                return 0;
            }
        }
    }

}