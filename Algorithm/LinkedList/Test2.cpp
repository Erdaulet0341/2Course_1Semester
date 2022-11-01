#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node *link;
};
int size=0;

class LinkedList{
    private:
        node *head, *tail;
    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }


        int getSize(){
            return size;
        }
        char getTail(){
            return tail->data;
        }
        char getHead(){
            if(head == NULL) return '-';
            else return head->data;
        }


        void push_back(char c){
            node *temp = new node();
            temp->data = c;
            temp->link = NULL;
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->link = temp;
                tail = tail->link;
            }
            size++;
        }
        void push_front(char c){
            node *temp = new node();
            temp->data = c;
            temp->link = head;
            head = temp;
            size++;  
        }
        void insertByIndex(int n, char c){
            node *newNode = new node();
            newNode->data = c;
            newNode->link = NULL;
            if(n == 0){
                push_front(c);
            }
            else if(n<1 || n>size){
                cout << "Invalid position!" << endl;
            }
            else{
                node *cur = head;
                int cnt = 1;
                while(cnt!=n){
                    cur = cur->link;   /// a b d -> c => a b c d;
                    cnt++;
                }
                newNode->link = cur->link;
                cur->link = newNode;
                size++;
            }
        }


        void print(){
            node *temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->link;
            }
        }
        void PrintByIndex(int n){
            int cnt = 0;
            node *temp = head;
            while(cnt!=n){
                temp = temp->link;
                cnt++;
            }
            cout << temp->data;
        }

        
        void reverse(){
            struct node *temp = NULL;
            struct node *prev = NULL;
            struct node *current = head;
            while(current != NULL) {
                temp = current->link;
                current->link = prev;
                prev = current;
                current = temp;
            }
            head = prev;
        }
        void pop_end(){
            node *temp = head;
            while(temp->link->link != NULL){
                temp = temp->link;
            }
            delete temp->link;
            tail = temp;
            tail->link = NULL;
            size--;
        }
        void pop_front(){
            node *temp = head;
            head = temp->link;
            delete temp;
            size--;
        }
        void deleteByIndex(int n){
            node *cur = head;
            int cnt = 0;
            if(n == 0){
                head = cur->link;
                delete cur;
            }
            else if(n<0 || n>size-1){
                cout << "Invalid index!" << endl;
                size++;
            }
            else{
                while(cnt!=n-1){
                    cur = cur->link;
                    cnt++;
                }
                cur->link = cur->link->link;
            }
            size--;
        }
        void clear(){
            node *temp = NULL;
            node *cur = head; 
            while(cur != NULL){
                temp = cur->link;
                delete cur;
                cur = temp;
                size--; 
            }
            head = NULL;
        }

};

int main(){
    LinkedList l;
    l.push_back('C');
    l.push_back('A');
    l.push_back('g');
    l.push_back('f');
    l.push_back('l');
    l.print();
    cout << endl;
    cout << "Size = " << l.getSize() << endl;
    cout << "Head = " << l.getHead() << endl;
    l.push_front('J');
    cout << "Head = " << l.getHead() << endl;
    l.push_front('1');
    cout << "Size = " << l.getSize() << endl;
    l.print();
    cout << endl;
    l.insertByIndex(1, 'v');
    l.print();
    cout << "Size = " << l.getSize() << endl;
    l.deleteByIndex(1);
    l.print();
    cout << endl;
    cout << "Size = " << l.getSize() << endl;
    return 0;
}