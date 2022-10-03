#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++){
        int k; cin >> k;
        v.push_back(k);
    }
    int k; cin >> k;
    sort(v.begin(), v.end());
    int first=0, last = v.size()-1, middle;
    while (first<=last){
        middle = first + (last - first)/2;
        if(v[middle] > k){
            last = middle - 1;
        }
        else if(v[middle] < k){
            first = middle +1;
        }
        else{
            cout << middle;
            break;
        }
    }
}