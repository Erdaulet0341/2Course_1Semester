#include <bits/stdc++.h>
using namespace std;

void f1(string text, vector<int> &L)
{
    L[0] = 0;
    int len = 0;
    int i = 1;
    while (i < text.length())
    {
        if (text[i] == text[len])
        {
            len++;
            L[i] = len;
            i++;
            continue;
        }
        else
        {
            if (len == 0)
            {
                L[i] = 0;
                i++;
                continue;
            }
            else
            {
                len = L[len - 1];
                continue;
            }
        }
    }
}

vector<int> f2(string parasite, string text)
{
    int n = text.length();
    int m = parasite.length();
    vector<int> L(m);
    vector<int> ans;
    f1(parasite, L);
    int i = 0, j = 0;
    while (i < n)
    {
        if (parasite[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            ans.push_back(i - m);
            j = L[j - 1];
        }
        else if (i < n && parasite[j] != text[i])
        {
            if (j == 0)
                i++;
            else
                j = L[j - 1];
        }
    }
    return ans;
}

int main()
{
    string t1, t2, pat;
    cin >> t1 >> t2 >> pat;

    vector<int> vt1;
    vector<int> vt2;

    vt1 = f2(pat, t1);
    vt2 = f2(pat, t2);

    vector<int> res;
    set_intersection(vt1.begin(), vt1.end(), vt2.begin(), vt2.end(), back_inserter(res));
    cout << res.size();

    
    return 0;
}