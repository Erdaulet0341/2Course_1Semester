#include <iostream>
#include <set>

using namespace std;


int main(){
    int n; cin >> n;
    set<int> st;
    for(int i=0; i<n; i++){
        int x ; cin >> x;
        st.insert(x);
    }
    set<int>::iterator itr;
    int sum=0;
    for (itr = st.begin(); itr != st.end(); itr++) {
        sum+=*itr;
    }
    cout << sum;
}