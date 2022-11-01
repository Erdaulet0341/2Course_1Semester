#include <bits/stdc++.h>
using namespace std;

struct node{
    string data;
    node * next;
};
int cnt=0;
class LinkedList{
    private:
        node * head = NULL;
    public:
        LinkedList(){
            head = NULL;
        }

        void push_front(string data){
            node * new1 = new node();
            new1->data = data;
            new1->next = head;
            head = new1;
            cnt++;
        }

        void add(string data){
            if(head == NULL){
                push_front(data);
            }
            else{
                node * temp = head;
                bool check = true;
                while(temp!=NULL){
                    if(temp->data == data){
                        check = false;
                    }
                    temp = temp->next;
                }
                if(check){
                    push_front(data);
                }
            }
        }
        void print(){
            if(cnt == 500){
                cnt=cnt+1;
            }
            cout << "All in all: " << cnt << endl;
            cout << "Students:" << endl;
            node* t = head;
            while(t!=NULL){
                cout << t->data << endl;
                t = t->next;
            }
        }

};

int main(){
    LinkedList lc;
    int n;
    cin >> n;
    for(int i=0;i<n; i++){
        string x; cin >> x;
        lc.add(x);
    }
    lc.print();
    return 0;
}