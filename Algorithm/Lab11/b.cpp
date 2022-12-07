#include <iostream>
using namespace std;


int main(){
    int n, ans = 1e9, total = 0; 
    
    cin >> n; 
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ans = min(ans, arr[i]);
        total += arr[i];
    }


    cout << (n-1) * ans + total - ans;

    return 0;
}