#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    for (int i =0; i<n; i++){
        cin >> arr[i];
    }
    int nol[1003];
    for (int i=0; i<1003; i++){
        nol[i] = 0;
    }

    for(int i = 0; i<n; i++){
        nol[arr[i]]++;
    }
    int max = -1;
    for (int i=0; i<1003; i++){
        if (max<nol[i]){
            max = nol[i];
        }
    }
    int cnt = 0;
    for (int i=0; i<1003; i++){
        if (max==nol[i]){
            cnt++;
        }
    }
    int arr1[cnt];
    int j=0;
    for (int i=0; i<1003; i++){
        if (max==nol[i]){
            arr1[j]=i;
            j++;
        }
    }
    for(int i=cnt-1; i>=0; i--){
        cout << arr1[i] << " ";
    }
    
}