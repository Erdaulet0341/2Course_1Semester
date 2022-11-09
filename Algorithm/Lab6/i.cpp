#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merger(string & s, int left, int mid, int right){
    int nl = mid - left +1;
    int nr = right - mid;
    //cout << nl << ' ' << nr << endl;
    string l="", r="";
    for(int i=0; i<nl; i++){
        l+=s[i+left];
    }
    for(int i=0; i<nr; i++){
        r+=s[i+1+mid];
    }
    //cout << l << " " << r << endl;

    int il=0, ir=0, is=left;
    while(il<nl && ir<nr){
        if((l[il] <= r[ir])){
            //cout << "no" << endl;
            s[is] = l[il];
            //cout << "s=" << s<<"---" << "s[is]=" << s[is] << "---" << "l[il="<< l[il] << endl;
            il++;
        }
        else{
            //cout << "s=" << s<<"---" << "s[is]=" << s[is] << "---" << "r[ir="<< r[ir] << endl;
            //cout << "yes" << endl;
            s[is] = r[ir];
            ir++;
        }
        is++;
    }

    while(il<nl){
        s[is] = l[il];
        il++; is++;
    }
    while(ir<nr){
        s[is] = r[ir];
        ir++; is++;
    }

}

void merge_sort(string & s, int left, int right){
    if(left<right){
        int mid = left + (right - left) / 2;
        merge_sort(s, left, mid);
        merge_sort(s, mid+1, right);
        merger(s, left, mid, right);
    }
}


int main(){
    string s;
    cin >> s;
    merge_sort(s, 0, s.size()-1);
    for (int i=0; i<s.size(); i++){
        cout << s[i];
    }
}