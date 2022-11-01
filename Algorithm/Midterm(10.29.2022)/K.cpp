#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution{
    private: 
        int n;
    public:
    solution(){
        int x; cin>>x;
        this->n = x;
        answer();
    }
    vector<int> v;
    void answer(){
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x==1){
                int l;
                cin >> l;
                v.push_back(l);
            }
            else{
                reverse(v.begin(), v.end());
            }
        }
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
    }

};

int main(){
    solution s;
    return 0;
}