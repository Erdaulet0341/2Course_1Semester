#include <iostream>
#include <vector>
using namespace std;

int zer[100005];

vector<int> prime(int n){
    vector<int> v;
    for(int i=2; i*i<=n; i++){
        if(zer[i]==0){
            int k=i; 
            while(k<=n){
                k+=i;
                zer[k]=1;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(zer[i]==0){
            v.push_back(i);
        }
    }

    return v;
}

int main(){
    int n;
    cin >> n;
    vector<int> v = prime(n);

    for(int i=0; i<v.size(); i++){
        for(int j=i; j<v.size(); j++){
            if(v[i]+v[j]==n){
                cout << v[i] << " " << v[j];
                return 0;
            }
        }
    }

    return 0;
}