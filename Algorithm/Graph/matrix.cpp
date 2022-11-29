#include <iostream>
#include <vector>
using namespace std;

int g[100][100];

int main(){
    int n, m, x, y;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> x >> y; // 1 3
        g[x][y] = 1;
        g[y][x] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}