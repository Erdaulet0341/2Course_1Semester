#include <iostream>
#include <stack>
using namespace std;

int find_max(stack<int> st){
    int max = st.top();
    while(!st.empty()){
        if(max<st.top()){
            max = st.top();
        }
        st.pop();
    }
    return  max;
}

int main(){
    stack<int> st;
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
            if(!st.empty())
                cout << find_max(st) << endl;
            else
                cout << "error" << endl;
        }
    }


    return 0;
}