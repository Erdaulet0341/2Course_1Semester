#include <bits/stdc++.h>
  
using namespace std;

struct node{
	node * prev;
	node * next;
	string data;
};
int size = 0;
class DoubleLinkedList{
    private:
        node *head;
        node *tail;
    public:
        DoubleLinkedList(){
            head = NULL;
            tail = NULL;
        }

        void add_back(string s){
            node *newNode = new node();
            newNode->data = s;
            newNode->next = NULL;
            newNode->prev = NULL;
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        void add_front(string s){
            node *newNode = new node();
            newNode->data = s;
            newNode->next = NULL;
            newNode->prev = NULL;
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
        }
        bool empty(){
            return head==NULL;
        }
        void erase_front(){
            if(head == tail){
                head = NULL;
                tail =NULL;
            }
            else{
                node *temp = head;
                head = temp->next;
                head->prev = NULL;
                delete temp;
            }
        }
        void erase_back(){
            if(head == tail){
                head = NULL;
                tail =NULL;
            }
            else{
                node *last = tail;
                tail = last->prev;
                tail->next = NULL;
                delete last;
            }
        }
        string front(){
            return head->data;
        }
        string back(){
            return tail->data;
        }
        void clear(){
            node *temp = head;
            node *cur = NULL;
            while(temp != NULL){
                cur = temp;
                temp = temp->next;
                delete cur;
            }
            head = NULL;
            tail = NULL;
        }
        void print(){
            node *temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            } 
        }
};
  
int main()
{
    DoubleLinkedList dll;

	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			dll.add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			dll.add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(dll.empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << dll.front() << endl;
   				dll.erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(dll.empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << dll.back() << endl;
   				dll.erase_back();
   			}
   		}
   		if(s == "front"){
   			if(dll.empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << dll.front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(dll.empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << dll.back() << endl;
   			}
   		}
   		if(s == "clear"){
   			dll.clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}  
    return 0;
}