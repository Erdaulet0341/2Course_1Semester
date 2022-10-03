#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, long long arr[], int n, int K)
{
    long long count = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {

        if (arr[i] > mid)
            return false;

        sum += arr[i];
 
        if (sum > mid) {
            count++;
            sum = arr[i];
        }
    }
    count++;

    if (count <= K)
        return true;
    return false;
}

long long solve(long long arr[], int n, int K)
{
    long long* max = max_element(arr, arr + n);
    long long start = *max;
    long long end = 0;
 
    for (int i = 0; i < n; i++) {
        end += arr[i]; 
    }

    long long answer = 0;
    while (start <= end) {
        long long mid = start + (end-start) / 2;
 
        if (check(mid, arr, n, K)) {
            answer = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
 
    return answer;
}

int main(){
    int n, k;
    cin >> n >> k;
    long long arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << solve(arr, n, k);
    
}