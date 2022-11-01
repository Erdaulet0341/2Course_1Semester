#include <iostream>
using namespace std;

int main(){
    int n;int k;
    cin >> n >> k;
    string s;
    int b, box = 0;;
    long long sum=0;
    while(n--){
        cin >> s;
        if(s=="print"){
            cout << sum << endl;
        }
        else if(s == "insert"){
            cin >> b;
            sum+=b;
            box++;
        }
        if(box>k){
            break;
        }
    }
}