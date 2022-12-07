#include <iostream>
using namespace std;

int n, q;
int arr[1005][1005];

int main(){
    
	cin >> n >> q;
    bool isTrue[q];
	for (int i =1; i<=n; i++){
		for (int j = 1; j <=n; j++){ 
			cin >> arr[i][j];
        }
    }
	for (int i = 0; i < q; i++){
		int c1, c2, c3;
		cin >> c1 >> c2 >> c3;
		if (arr[c1][c2] && arr[c1][c3] && arr[c2][c3]){
			isTrue[i] =1;
        }
		else{
			isTrue[i]=0;
        }
	}
    for(int z = 0; z< q; z++){
        if(isTrue[z]){
            cout<<"YES" << endl;
        }
        else{
            cout<< "NO" << endl;
        }
    }
	return 0;
}