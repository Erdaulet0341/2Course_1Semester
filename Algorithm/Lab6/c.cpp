#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void MergeSortedIntervals(vector<int>& v, int s, int m, int e) {
	
	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

void MergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

int main(){
    int n; cin >> n;
    int arr[n];
    vector<int> v;

    for(int i=0; i<n; i++) cin >> arr[i];
    
    int maxAbs = abs(arr[0]-arr[1]);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(maxAbs > abs(arr[i] - arr[j])){
                maxAbs = abs(arr[i] - arr[j]);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(maxAbs == abs(arr[i] - arr[j])){
                v.push_back(arr[i]);
                v.push_back(arr[j]);
            }
        }
    }
    MergeSort(v, 0, v.size()-1);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}