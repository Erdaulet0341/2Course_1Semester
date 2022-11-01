#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> final;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        final.push_back(x);
    }
    
    int n2;
    cin >> n2;

    for (int i=0; i<n2; i++){
        int x;
        cin >> x;
        final.push_back(x);
    }
    
    sort(final.begin(), final.end());
    for (int i=0; i<final.size(); i++){
        cout << final[i] << " ";
    }
}