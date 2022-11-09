#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    double gpa;
    string name;
    string fam;

    Solution() {}

    Solution(double gpa, string name, string fam) {
        this->gpa = gpa;
        this->name = name;
        this->fam = fam;
    }

    bool sortSrt(string a, string b) {
        int size = 0;
        if(a.size() < b.size()) size = a.size();
        else size = b.size();
        
        for(int i = 0;i < size;i++) {
            if(a[i]<b[i]) return true;
            else if(a[i]>b[i]) return false;
        }
        if(size == a.size()) return true;
        else return false;
    }

    bool sortGPA(Solution b) {
        if(this->gpa < b.gpa) return true;
        else if(this->gpa == b.gpa) {
            if(this->name == b.name) {
                return sortSrt(this->fam,b.fam);
            }
            else {
                return sortSrt(this->name, b.name);
            }
        }
        return false;
    }
};

vector<Solution> solutions;

void merge(int  left, int  mid, int  right) {
    int  nl = mid - left + 1;
    int  nr = right - mid;
 
    vector<Solution> l(nl);
    vector<Solution> r(nr);
    
    for (int i = 0; i < nl; i++)
        l[i] = solutions[left + i];
    for (int j = 0; j < nr; j++)
        r[j] = solutions[mid + 1 + j];
 
    int il = 0;
    int ir = 0;
    int iv = left;
 
    while (il < nl && ir < nr) {
        if (l[il].sortGPA(r[ir])) {
            solutions[iv] = l[il];
            il++;
        }
        else {
            solutions[iv] = r[ir];
            ir++;
        }
        iv++;
    }

    while (il < nl) {
        solutions[iv] = l[il];
        il++;
        iv++;
    }

    while (ir < nr) {
        solutions[iv] = r[ir];
        ir++;
        iv++;
    }
    l.clear();
    r.clear();
}

void mergeSort(int  left, int  right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

int main() {
    int n;cin>>n;
    map<string,double> mp; 
    mp["F"] = 0.0;
    mp["D"] = 1.0;
    mp["D+"] = 1.5;
    mp["C"] = 2.0;
    mp["C+"] = 2.5;
    mp["B"] = 3.0;
    mp["B+"] = 3.5;
    mp["A"] = 3.75;
    mp["A+"] = 4.0;

    for(int i = 0;i < n;i++) {
        string name,fam;cin>>name>>fam;
        int objects;cin>>objects;
        int total = 0;
        double sum = 0;
        for(int j = 0;j < objects;j++) {
            string mark; int credit;
            cin>>mark>>credit;
            sum+=mp[mark]*credit;
            total += credit;
        }
        double gpa = sum/total;
        Solution sol;
        sol.gpa = gpa;
        sol.name = name;
        sol.fam = fam;
        solutions.push_back(sol);   
    }
    mergeSort(0,n-1);
    for(int i = 0;i < solutions.size();i++) {
        cout << solutions[i].name << " " << solutions[i].fam << " " << fixed  << setprecision(3) << solutions[i].gpa << endl;
    }

}