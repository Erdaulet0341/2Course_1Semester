#include <bits/stdc++.h>
using namespace std;

int binarySearch_increasing(int ar[], int target, int n){
  int left = 0, right = n - 1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if (target == ar[mid]) return mid;
    else if(target < ar[mid]) right = mid - 1; 
    else left = mid + 1;    
  }
  return -1;
}

int binarySearch_decreasing(int ar[], int target, int n){
  int left = 0, right = n - 1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if (target == ar[mid]) return mid;
    else if(target > ar[mid]) right = mid - 1; 
    else left = mid + 1; 
  }
  return -1;
}

int main() 
{
  int n;
  cin >> n;
  int ar[n];
  for(int i = 0; i < n; i++){
    cin >> ar[i];
  }
  int a, b;
  cin >> a >> b;
  int arr[a][b];
  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      cin >> arr[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < a; j++){
      int index;
      int size = sizeof(arr[j]) / sizeof(int);

      if (j % 2 == 0){
        index = binarySearch_decreasing(arr[j], ar[i], size);
      }
      else {
        index = binarySearch_increasing(arr[j], ar[i], size);
      }

      if (index != -1){
        cout << j << " " << index << endl;
        break;
      }
      else if (index == -1 && j + 1 == a) {
        cout << index << endl;
      }
    }
  }
}