#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    priority_queue<int> pq;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s=="add"){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(s=="delete"){
            if(!st.empty())
                st.pop();
            else
                continue;
        }
        else if(s == "getcur"){
            if(!st.empty()){
                cout << st.top() << endl;
            }
            else
                cout << "error" << endl;
        }
        else{
            if(!st.empty()){
                stack<int> temp = st;
                while(!temp.empty()){
                    pq.push(temp.top());
                    temp.pop();
                }
                cout << pq.top() << endl;
                while(!pq.empty()){
                    pq.pop();
                }
            }
            else
                cout << "error" << endl;
        }
    }


    return 0;
}