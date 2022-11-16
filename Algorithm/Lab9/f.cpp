#include <iostream>
#include <vector>
using namespace  std;

vector<int> v;

int count(string& text, string& pat){
    int n = text.size();
    int m = pat.size();
    int res = 0;
    for(int i=0; i<=n-m; i++){
        int j;
        for(j = 0; j<m; j++){
            if(text[i+j] != pat[j]) break;
        }
        if(j==m){
            res++;
            v.push_back(i+1);
        }
    }
    return res;
}

int main()
{
    string text, pat;
    cin >> text >> pat;
    cout << count(text, pat) << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
} 
