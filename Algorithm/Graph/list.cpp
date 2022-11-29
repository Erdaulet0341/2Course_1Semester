#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100];

int main(){
    int n, m, x, y;
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        cin >> x >> y; // 1 3, 1 2
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        cout << i << " - ";
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}