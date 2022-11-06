#include <iostream>
#include <stack>
using namespace std;

struct node{
    int data;
    node * next,* prev;
};

class Linked_list{
    private:
    node * head;
    node * tail;
    public:
    Linked_list(){
        head = NULL;
        tail = NULL;
    }

    void push_back(int data){
        node * new1 = new node();
        new1->data = data;
        new1->next = NULL;
        new1->prev = NULL;
        if(head == NULL){
            head = new1;
            tail = new1;
        }
        else{
            tail->next = new1;
            new1->prev = tail;
            tail = new1;
        }
    }

    void reverse(){
        stack<int> st;
        node * temp = head;
        while(temp!=NULL){
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
    }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout << temp->data <<  " ";
            temp = temp->next;
        }
    }

};

int main(){
    int n;
    cin >> n;
    Linked_list l;
    while(n--){
        int x; cin >> x;
        if(x==1){
            int z; cin >> z;
            l.push_back(z);
        }
        else{
            l.reverse();
        }
    }
    l.print();
    return 0;
}