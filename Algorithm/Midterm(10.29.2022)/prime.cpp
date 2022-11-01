// решата   Эратосфена

#include <iostream>
using namespace std;

int zero[1000000];

int main(){
    int n;
    cin >> n;
    for(int i=2; i<=10; i++){
        cout << zero[i] << " ";
    }

    for (int i=2; i*i<=n; i++){
        if(zero[i]==0){
            int k=i; 
            while(k+i<=n){
                k+=i;
                zero[k]=1;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(zero[i]==0){
            cout << i << " ";
        }
    }

    return 0;
}