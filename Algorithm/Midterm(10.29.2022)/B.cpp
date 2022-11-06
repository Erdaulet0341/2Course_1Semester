#include<bits/stdc++.h>
using namespace std;

int beknur[100005];

vector<int> prime(int n){
    vector<int> vt;
    for(int i=2; i*i<=n; i++){
        if(beknur[i]==0){
            int k=i; 
            while(k<=n){
                k+=i;
                beknur[k]=1;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(beknur[i]==0){
            vt.push_back(i);
        }
    }

    return vt;
}

int main(){
    int n;
    cin >> n;
    vector<int> vt = prime(n);

    for(int i=0; i<vt.size(); i++){
        for(int j=i; j<vt.size(); j++){
            if(vt[i]+vt[j]==n){
                cout << vt[i] << " " << vt[j];
                return 0;
            }
        }
    }

    return 0;
}