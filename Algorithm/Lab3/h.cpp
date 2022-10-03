#include <bits/stdc++.h>
using namespace std;

bool  binarySearch(vector<int> arr, int first, int last, int x){
    while(first<=last){
        int  mid = first + (last - first) / 2;
        if(arr[mid] > x){
            last = mid -1;
        }
        else if(arr[mid] < x){
            first = mid +1;
        }
        else return true;
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr_n[n], arr_m[m];
    for (int i=0; i<n; i++){
        cin >> arr_n[i];
    }
    for (int i=0; i<m; i++){
        cin >> arr_m[i];
    }
    vector<int> arr_p;
    vector<vector<int> > vv;
    int l = 0, temp=1;
    for (int i=0; i<n; i++){
        for(int j=temp; j<arr_n[i]+temp; j++){
            arr_p.push_back(j);
            l++;
        }
        temp = temp + arr_n[i];
        vv.push_back(arr_p);
        arr_p.clear();
        l=0;
    }
    for(int j=0; j<m; j++){
        for(int i=0; i<vv.size(); i++){
            if(binarySearch(vv[i], 0, vv[i].size()-1, arr_m[j])){
                cout << i+1 << endl;
            }
        }
    }
}