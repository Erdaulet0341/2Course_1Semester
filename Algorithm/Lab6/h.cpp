#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    char arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    char c; cin >> c;
    for(int i=0; i<n; i++){
        if(c < arr[i]){
            cout << arr[i];
            break;
        }
        else if(i==n-1){
            cout << arr[0] ;
            break;
        }
    }
    return 0;
}