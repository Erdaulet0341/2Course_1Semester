#include <bits/stdc++.h>
using namespace std;

int binarySearchOdd(vector<int> v, int x){
    int first = 0, last = v.size()-1;
    while(first<=last){
        int mid = first + (last - first) / 2;
        if(v[mid]>x){
            last = mid-1;
        }
        else if(v[mid] < x){
            first = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

bool binarySearchOddBool(vector<int> v, int x){
    int first = 0, last = v.size()-1;
    while(first<=last){
        int mid = first + (last - first) / 2;
        if(v[mid]>x){
            last = mid-1;
        }
        else if(v[mid] < x){
            first = mid+1;
        }
        else{
            return true;
        }
    }
    return -1;
}

int binarySearchEven(vector<int>v, int x){
    int first = 0, last = v.size()-1;

    while(first<=last){
        int mid = first + (last - first) / 2;
        if(v[mid]>x){
            first = mid+1;
        }
        else if(v[mid] < x){
            last = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

bool binarySearchEvenBoll(vector<int>v, int x){
    int first = 0, last = v.size()-1;

    while(first<=last){
        int mid = first + (last - first) / 2;
        if(v[mid]>x){
            first = mid+1;
        }
        else if(v[mid] < x){
            last = mid-1;
        }
        else{
            return true;
        }
    }
    return false;
}


int main(){
    int t; cin >> t;
    vector<int> v;
    for(int i; i<t; i++){
        int k; cin >> k;
        v.push_back(k);
    }
    int n, m; cin >> n>> m;
    vector<int> v1;
    vector<vector<int> > vv;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int x; cin >>x;
            v1.push_back(x);
        }
        vv.push_back(v1);
        v1.clear();
    }
    for (int i=0; i<t; i++){
        for(int j=0; j<n; j++){
            if(j%2==0){
                if(binarySearchOdd(vv[j], v[i]) ==-1){
                    cout << -1 << endl;
                }
                else{
                    cout << j << " " << binarySearchOdd(vv[j], v[i]) << endl;
                }
            }
            else{
                if(binarySearchEven(vv[j], v[i])==-1){
                    cout << -1 << endl;
                }
                else{
                    cout << j << " " << binarySearchEven(vv[j], v[i]) << endl;
                }
            }
        }
    }
}