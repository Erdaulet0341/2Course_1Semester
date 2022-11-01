#include <iostream>
using namespace std;

int main()
{
  long long n;
  cin >> n;
  long long cnt=0;
  long long a[n+1];
  for (long long i = 0; i < n + 1; i++)
    a[i] = i;
  for (long long p = 2; p < n + 1; p++)
  {
    if (a[p] != 0)
    {
      if(n%a[p]==0){
        cnt++;
      }
      for (long long j = p*p; j < n + 1; j += p)
        a[j] = 0;
    }
  }
  cout << cnt;
  return 0;
}