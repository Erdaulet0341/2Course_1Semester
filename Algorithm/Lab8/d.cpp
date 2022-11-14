#include <iostream>
#include <vector>
using namespace std;

int count(string& pat, string& txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M) {
            res++;
        }
    }
    return res;
}

int main(){
    int n;
    string s, text;
    vector<string> v;
    bool check = true;
    while(check){
        cin >> n;
        if(n==0){
            check = false;
            break;
        }
        for(int i=0; i<n; i++){
            cin >> s;
            v.push_back(s);
        }
        cin >> text;
        int q=0;
        int max=0;
        for(int i=0; i<n; i++){
            if(max<count(v[i], text)) max = count(v[i], text);
        }
        int maxcnt=0;
        for(int i=0; i<n; i++){
            if(max==count(v[i], text)){
                if(maxcnt == 0){
                    cout << max << endl;
                    maxcnt++;
                }
                cout << v[i] << endl;
            }
        }
        v.clear();
    }
}