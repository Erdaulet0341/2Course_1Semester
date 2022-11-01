#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v1;
    vector<int> v2;;
    for (int i=0;i<n; i++){
        int x; cin >> x;
        if(x%2==0){
            v1.push_back(x);
        }
        else{
            v2.push_back(x);
        }
    }
    for(int i=0; i<v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;
    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    if(v1.size()>=v2.size()){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}