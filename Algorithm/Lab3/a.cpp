#include <iostream>
using namespace std;

int binaryInc(int arr[], int x, int n){
    int first = 0, mid;
    int last = n-1;
    while(first<=last){
        mid = first + (last - first) / 2;
        if(arr[mid]>x){
            first = mid+1;
        }
        else if(arr[mid]<x){
            last = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int binaryDec(int arr[], int x, int n){
    int first = 0, mid;
    int last = n-1;
    while(first<=last){
        mid = first + (last - first) / 2;
        if(arr[mid]<x){
            first = mid+1;
        }
        else if(arr[mid]>x){
            last = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int a, b; cin >> a >> b;
    int mat[a][b];
    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++){
            cin >> mat[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<a; j++){
            if (j%2!=0){
                if(binaryDec(mat[j], arr[i], b)!=-1){
                    cout << j << " "<< binaryDec(mat[j], arr[i], b) << endl;
                    break;
                }
                else if(j == (a-1)){
                    cout << -1 << endl;
                }
            }
            else{
                if(binaryInc(mat[j], arr[i], b) != -1){
                    cout << j << " "<< binaryInc(mat[j], arr[i], b)  << endl;
                    break;
                }
                else if(j == (a-1)){
                    cout << -1 << endl;
                }
            }
        }
    }
}

// 25 17 15 14 10 9   9

// 1 2 3
// 4 5 6