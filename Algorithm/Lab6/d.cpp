#include <iostream>
#include <typeinfo>
#include <tuple>
#include <vector>
using namespace std;

int toInt(string s){
    if(s.size()==2){
        int x = s[0] - '0';
        int y = s[1] - '0';
        return x*10+y;
    }
    else{
        int a = s[0]-'0';
        int b = s[1]-'0';
        int c = s[2]-'0';
        int d = s[3]-'0';
        return a*1000+b*100+c*10+d;
    }
}

bool Greater(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    if(get<2>(t1) < get<2>(t2)) return true;
    else if(get<2>(t1) == get<2>(t2)) {
        if(get<1>(t1) < get<1>(t2)) return true;
        else if(get<1>(t1) == get<1>(t2)) {
            if(get<0>(t1) < get<0>(t2)) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

void merge(vector<tuple<int, int, int> >& v, int left, int m, int right){
    int nl = m - left + 1; 
    int nr = right - m;

    vector<tuple<int, int, int> > l;
    vector<tuple<int, int, int> > r;

    for(int i=0; i<nl; i++){
        l.push_back(v[i+left]);
    }
    for(int i=0; i<nr; i++){
        r.push_back(v[m+i+1]);
    }

    int il,ir,iv=left;
    il=ir=0;
    while(il<nl && ir<nr){
        if(Greater(l[il], r[ir])){
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
    l.clear();
    r.clear();

}

void merge_sort(vector<tuple<int, int, int> >& v, int left, int right){
    if(left<right){
        int mid = left + (right - left) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}


int main(){
    vector<tuple<int, int, int> > v;
    int n;
    cin >> n;
    int day, month, year;
    string d="", m="", y="";
    for(int i=0; i<n; i++){
        string s;cin >>s;
        d+=s[0]; d+=s[1];
        m+=s[3]; m+=s[4];
        y+=s[6]; y+=s[7]; y+=s[8]; y+=s[9];
        day = toInt(d); month = toInt(m); year = toInt(y);
        v.push_back(make_tuple(day, month, year));
        d=""; m=""; y="";
    }
    merge_sort(v, 0, v.size()-1);
    for(int i=0; i<v.size(); i++){
        if(get<0>(v[i]) <10) cout << 0 << get<0>(v[i]) << "-";
        else cout << get<0>(v[i]) << "-";
        if(get<1>(v[i]) <10) cout << 0 << get<1>(v[i]) << "-";
        else cout << get<1>(v[i]) << "-";
        cout << get<2>(v[i]) << endl;
    }
}
