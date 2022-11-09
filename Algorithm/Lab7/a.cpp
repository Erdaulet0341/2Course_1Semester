#include <bits/stdc++.h>
using namespace std;

vector<string> final;

bool sizeSort(string a, string b) {
    if(a.size() == b.size()) return true;
    return a.size()<b.size();
}

void merge(int left, int mid, int right) {
    int nl = mid - left + 1;
    int nr = right - mid;
 
    vector<string> l_arr(nl);
    vector<string> r_arr(nr);
    
    for (int i = 0; i < nl; i++)
        l_arr[i] = final[left + i];
    for (int j = 0; j < nr; j++)
        r_arr[j] = final[mid + 1 + j];
 
    int il = 0;
    int ir = 0;
    int iv = left;
 
    while (il < nl && ir < nr) {
        if (sizeSort(l_arr[il],(r_arr[ir]))) {
            final[iv] = l_arr[il];
            il++;
        }
        else {
            final[iv] = r_arr[ir];
            ir++;
        }
        iv++;
    }

    while (il < nl) {
        final[iv] = l_arr[il];
        il++;
        iv++;
    }

    while (ir < nr) {
        final[iv] = r_arr[ir];
        ir++;
        iv++;
    }
    l_arr.clear();
    r_arr.clear();
}

void mergeSort(int left, int right) {
    if (left >= right)
        return;
    int m = left + (right - left) / 2;
    mergeSort(left, m);
    mergeSort(m+ 1, right);
    merge(left, m, right);
}

int main() {
    int n;
    cin>>n;
    string x;
    getline(cin, x);
    while(n--) { 
        string s;
        getline(cin,s);
        string sum = "";
        for(int i = 0;i < s.size();i++) {
            if(s[i] != ' ') sum+=s[i];
            else if(s[i] == ' ') {
                final.push_back(sum);   
                sum = "";
            }
        }
        final.push_back(sum);
        mergeSort(0, final.size() - 1);
        for(int i=0; i<final.size(); i++){
            cout << final[i] << " ";
        }
        cout << '\n';
        final.clear();
    }
}