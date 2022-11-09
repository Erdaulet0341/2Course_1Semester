#include <iostream>
#include <tuple>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

double find_GPA(vector< tuple<long long, string>> v){
    double c, sum=0, tot=0;
    string g;
    for(long long i=0; i<v.size(); i++){
        c = get<0>(v[i]);
        g = get<1>(v[i]);
        if(g=="A+") sum+=(4.00*c);
        if(g=="A") sum+=(3.75*c);
        if(g=="B+") sum+=(3.50*c);
        if(g=="B") sum+=(3.00*c);
        if(g=="C+") sum+=(2.50*c);
        if(g=="C") sum+=(2.00*c);
        if(g=="D+") sum+=(1.50*c);
        if(g=="D") sum+=(1.00*c);
        if(g=="F") sum+=(0*c);
        tot+=c;
    }
    return sum/tot;
}

bool stringIsSmaller(string a, string b) {
        long long size = 0;
        if(a.size() < b.size()) size = a.size();
        else size = b.size();
        
        for(long long i = 0;i < size;i++) {
            if(a[i]<b[i]) return true;
            else if(a[i]>b[i]) return false;
        }
        if(size == a.size()) return true;
        else return false;
    }

bool isSmallerThan(tuple<string, string, double>& v, tuple<string, string, double>& v2) {
        if(get<2>(v) < get<2>(v2)) return true;
        else if(get<2>(v) == get<2>(v2)) {
            if(get<1>(v) == get<1>(v2)) {
                return stringIsSmaller(get<0>(v), get<0>(v2));
            }
            else {
                return stringIsSmaller(get<1>(v), get<1>(v2));
            }
        }
        return false;
    }

void merge(vector<tuple<string, string, double> >& v, long long left, long long m, long long right){
    long long nl = m - left + 1; 
    long long nr = right - m;

    vector<tuple<string, string, double> > l;
    vector<tuple<string, string, double> > r;

    for(long long i=0; i<nl; i++){
        l.push_back(v[i+left]);
    }
    for(long long i=0; i<nr; i++){
        r.push_back(v[m+i+1]);
    }

    long long il,ir,iv=left;
    il=ir=0;
    while(il<nl && ir<nr){
        if(isSmallerThan(l[il], r[ir])){
            swap(v[iv], l[il]);
            il++;
            iv++;
        }
        else{
            swap(v[iv], r[ir]);
            ir++;
            iv++;
        }
    }

    while(il<nl){
        swap(v[iv], l[il]);
        iv++; il++;
    }
    while(ir<nr){
        swap(v[iv], r[ir]);
        iv++; ir++;
    }

}

void merge_sort(vector<tuple<string, string, double> >& v, long long left, long long right){
    if(left<right){
        long long mid = left + (right - left) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}

int main(){
    long long n; cin >> n;
    vector<tuple<long long, string> > v;
    vector<tuple<string, string, double> > ans;
    string name, fam;
    long long sub, credit;
    string g;    
    for(long long i=0; i<n; i++){
        cin >> fam >> name >> sub;
        for(long long j=0; j<sub; j++){
            cin >>  g >> credit;
            v.push_back(make_tuple(credit, g));
        }
        ans.push_back(make_tuple(fam, name, find_GPA(v)));
        v.clear();
    }
    
    merge_sort(ans, 0, ans.size()-1);
    
    for(long long i=0; i<ans.size(); i++){
        cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " "<< fixed << setprecision(3)<< get<2>(ans[i]) << "\n";
    }

    return 0;
}