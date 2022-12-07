#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = -1;
    }

    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int s, t;
    cin >> s >> t;
    s--; t--;

    queue<int> q;
    arr[s] = 0;
    q.push(s);
    while (q.size() > 0)
    {
        int x = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(a[x][i] == 1 && arr[i] == -1){
                arr[i] = arr[x] + 1;
                q.push(i);
            }
        }
    }
    
    cout << arr[t];




    return 0;
}