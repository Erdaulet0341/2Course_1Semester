#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int n; cin >> n;

    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int k; cin >> k;
    int l, index;
    int min = 111111111;
    for (int i=0; i<n; i++){
        l = abs(arr[i]-k);
        if (min>l){
            min = l;
            index = i;
        }
    }
    cout << index;

}