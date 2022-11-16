#include <bits/stdc++.h>
using namespace std;
#define longg long long

int hashh(string s1, string s2, string parasite){
    longg mod = 9007199254740879; int d = 31;
    longg hashs1 = 0, hashs2 = 0, hashpattern = 0, h = 1, cnt = 0;
    for(int i = 0; i < parasite.size() - 1; i++){
        h = (h * d) % mod;
    }
    for(int i = 0; i < parasite.size(); i++){
        hashs1 = (hashs1 * d + s1[i]) % mod;
        hashs2 = (hashs2 * d + s2[i]) % mod;
        hashpattern = (hashpattern * d + parasite[i]) % mod;
    }
    longg size = min(s1.size(), s2.size());
    for(int i = 0; i <= size - parasite.size(); i++){
        if(hashpattern == hashs1 && hashpattern == hashs2){
            cnt++;
        }
        if(i < size - parasite.size()){
            hashs1 = (d * (hashs1 - s1[i] * h) + s1[i + parasite.size()]) % mod;
            hashs2 = (d * (hashs2 - s2[i] * h) + s2[i + parasite.size()]) % mod;
            if(hashs1 < 0) hashs1 += mod;
            if(hashs2 < 0) hashs2 += mod;
        }
    }
    return cnt;
}

int main(){
    string s1,s2, parasite;
    cin >> s1 >> s2 >> parasite;
    cout << hashh(s1, s2, parasite);
}