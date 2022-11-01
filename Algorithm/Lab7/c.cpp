#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int max1[1000],max2[1000];

    for(int i=0; i<1000; i++){
        max1[i] = 0, max2[i] = 0;
    }

    for (int i=0; i<n; i++){
        int x; cin >> x;
        max1[x]++;
    }

    for (int i=0; i<m; i++){
        int x; cin >> x;
        max2[x]++;
    }

    for (int i=0; i<1000; i++){
        if(max1[i]!= 0 and max2[i] != 0){
            if(max1[i]>0 && max2[i]>0){
                if(max1[i]>max2[i]){
                    for(int k=0; k<max2[i]; k++){
                    cout << i << " ";
                }
                }
                else{
                    for(int k=0; k<max1[i]; k++){
                        cout << i << " ";
                    }
                }
            }
        }
    }
}