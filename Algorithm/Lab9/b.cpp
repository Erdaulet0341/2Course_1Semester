#include <iostream>
using namespace std;

int count(string& pat, string& txt)
{
    int M = pat.length(); //2
    int N = txt.length(); //6
    int res = 0;
    for (int i = 0; i <= N - M; i++) { /// qaqzaq
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j]) //  aq
                break;
        if (j == M) {
            res++;
        }
    }
    return res;
}

int c(string& text, string& pap){
    int n = text.size();
    int m = pap.size();
    int res=0;

    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m; j++){
            if(text[i+j] != pap[j])
                break;
        }
        if(j==m){
            res++;
        }
    }
    return res;
}


int main(){
    string s, pop;
    int k;
    cin  >> s >> k >> pop;

    if(c(pop, s)<k) cout << "NO";
    else cout << "YES";


    return 0;
}