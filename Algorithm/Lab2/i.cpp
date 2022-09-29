#include <bits/stdc++.h>
  
using namespace std;

int main()
{
	deque<string> deq;
	string s;
	bool b = true;
   	while(b){
		cin >> s;
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			deq.push_front(t);
   			cout << "ok" << endl;
   		}
   		else if(s == "add_back"){
   			string t;
   			cin >> t;
   			deq.push_back(t);
   			cout << "ok" << endl;
   		}
   		else if(s == "erase_front"){
   			if(deq.size()==0){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << deq.front() << endl;
   				deq.pop_front();
   			}
   		}
   		else if(s == "erase_back"){
   			if(deq.size()==0){
   				cout << "error" << endl;
   			}
   			else{
   				cout << deq.back() << endl;
   				deq.pop_back();
   			}
   		}
   		else if(s == "front"){
   			if(deq.size()==0){
   				cout << "error" << endl;
   			}
   			else{
   				cout << deq.front() << endl;
   			}
   		}
   		else if(s == "back"){
   			if(deq.size()==0){
   				cout << "error" << endl;
   			}
   			else{
   				cout << deq.back() << endl;
   			}
   		}
   		else if(s == "clear"){
   			deq.clear();
   			cout << "ok" << endl;
   		}
   		else if(s == "exit"){
   			cout << "goodbye" << endl;
			b = false;
   			break;
   		}
   	}
    return 0;
}