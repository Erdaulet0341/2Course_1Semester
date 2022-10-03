#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> powP;
    for (int i=0; i<n; i++){
        int k; cin >> k;
        powP.push_back(k);
    }
    int m; cin >> m;
    vector<int> powM;
    for (int i=0; i<m; i++){
        int k; cin >>k;
        powM.push_back(k);
    }
    int cnt=0, sum=0; 
    for (int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(powM[i]>=powP[j]){
                cnt++;
                sum+=powP[j];
            }
        }
        cout << cnt << " " << sum << endl;
        cnt = 0; sum = 0;
    }
}