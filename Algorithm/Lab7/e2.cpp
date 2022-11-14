#include <bits/stdc++.h>
using namespace std;

struct Solution {
    vector<int> v;
    long long sum;

    Solution() {}

    void print() {
        for(int i = 0;i < v.size();i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    bool greater(Solution b) {
        if(this->sum > b.sum) return true;
        else if(this->sum == b.sum) {
            for(int i = 0;i < b.v.size();i++) {
                if(this->v[i] != b.v[i]) return this->v[i]<b.v[i];
            }
        }
        else return false;
    }
};

vector<Solution> sol;

void merge(int left, int mid, int right) {
    int nl = mid - left + 1;
    int nr = right - mid;
 
    vector<Solution> l(nl);
    vector<Solution> r(nr);
    
    for (int i = 0; i < nl; i++)
        l[i] = sol[left + i];
    for (int j = 0; j < nr; j++)
        r[j] = sol[mid + 1 + j];
 
    int il = 0;
    int ir = 0;
    int iv = left;
 
    while (il < nl && ir < nr) {
        if (l[il].greater(r[ir])) {
            sol[iv] = l[il];
            il++;
        }
        else {
            sol[iv] = r[ir];
            ir++;
        }
        iv++;
    }

    while (il < nl) {
        sol[iv] = l[il];
        il++;
        iv++;
    }

    while (ir < nr) {
        sol[iv] = r[ir];
        ir++;
        iv++;
    }
    l.clear();
    r.clear();
}

void mergeSort(int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++) {
        Solution solu = Solution();
        long long sum = 0;
        for(int j = 0;j < m;j++) {
            int x;cin>>x;
            solu.v.push_back(x);
            sum+=x;
        }
        solu.sum = sum;
        sol.push_back(solu);
    }

    mergeSort(0,n-1);

    for(auto row : sol) {
        row.print(); 
    }    
}