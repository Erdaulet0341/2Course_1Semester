#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<string> deq;
    int n; cin >> n;
    int k; cin >> k;
    for (int i =0; i<n; i++){
        string s; cin >> s;
        deq.push_back(s);
    }
    deque<string> deq2;
    for (int i =0; i<n; i++){
        if(i==k){
            for(int j=n-1; j>=k; j--){
                    //linky2.addFirst(linky.get(j));
                    deq2.push_front(deq.at(j));
                }
                break;
        }
        else{
            //linky2.add(linky.get(i));
            deq2.push_back(deq.at(i));
        }
    }
    while(deq2.empty() == false){
        cout << deq2.front() << " ";
        deq2.pop_front();
    }
}