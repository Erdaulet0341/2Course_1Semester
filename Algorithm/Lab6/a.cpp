#include <iostream>
using namespace std;

void merger(string & s, int left, int mid, int right){
    int nl = mid - left +1;
    int nr = right - mid;
    string l="", r="";
    for(int i=0; i<nl; i++){
        l+=s[i+left];
    }
    for(int i=0; i<nr; i++){
        r+=s[i+1+mid];
    }

    int il=0, ir=0, is=left;
    while(il<nl && ir<nr){
        if((l[il] <= r[ir])){
            s[is] = l[il];
            il++;
        }
        else{
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string vowels="";
    string consonants="";

    for (int i=0; i<n; i++){
        char c = s[i];
        if(c == 'a' || c=='e' || c=='i' || c=='u' || c=='o'){
            vowels+=c;
        }
        else{
            consonants+=c;
        }
    }
    merge_sort(vowels, 0, vowels.size()-1);
    merge_sort(consonants, 0, consonants.size()-1);
    cout << vowels << consonants;

}