#include <bits/stdc++.h>
using namespace std;


int arr[100001];
int sets[100001];

int f(int v){
	if (v == arr[v]) return v;
	return arr[v] = f(arr[v]);
}

int main()
{
	int n, m ; cin >> n >> m;
	
    for(int i = 1; i<=n; i++){
        arr[i] = i;
	    sets[i] = i;
    }
	
    while(m--){
        int a,b; cin >> a >> b;
        a = f(a);
	    b = f(b);
	    if (a != b) {
		    if (sets[a] < sets[b]) swap(a, b);
		    arr[b] = a;
		    sets[a] += sets[b];
        }
    }

	int left,right; cin >> left >> right;
	if (f(left) == f(right)) cout << "YES";
    else cout << "NO";

	return 0;
}

