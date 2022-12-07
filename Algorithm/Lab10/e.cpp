#include <iostream>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }    

    while(q--){
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        if(arr[x1-1][x2-1] == 1 && arr[x2-1][x3-1] == 1 && arr[x1-1][x3-1] == 1){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    
    return 0;
}