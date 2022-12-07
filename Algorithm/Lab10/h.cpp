#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char> >& arr,int i, int j){
    if(i > arr.size()-1 || j > arr[0].size()-1 || i<0 || j<0 || arr[i][j] != '1'){
        return ;
    }
    arr[i][j] = '2';
    dfs(arr, i+1, j);
    dfs(arr, i, j+1);
    dfs(arr, i, j-1);
    dfs(arr, i-1, j);
}

int main(){
    int n,m; 
    cin >> n >> m;

    vector<vector<char> > arr;
    for(int i = 0; i<n; i++){
        vector<char> c;
        for(int j = 0; j < m; j++){
            char ch; cin >> ch;
            c.push_back(ch);
        }
        arr.push_back(c);
    }

    int cnt=0;

    for(int i=0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '1'){
                cnt++;
                dfs(arr,i,j);
            }
        }
    }
    cout << cnt;

    return 0;
}