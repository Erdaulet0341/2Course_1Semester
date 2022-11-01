#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * next;
    node * prev;
};
int size = 0;
class listDouble{
    private:
        node *head;
        node *tail;
    public:
        listDouble(){
            head = NULL;
            tail = NULL;
        }
        int getSize(){
            return size;
        }

        void push_front(int x){
            node * newNode = new node();
            newNode->data = x;
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
            size++;
        }

        void push_back(int x){
            node * newNode = new node();
            newNode->data = x;
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
            size++;
        }

        void push_index(int index, int data){
            node * newNode = new node();
            newNode->data = data;
            newNode->next = NULL;
            newNode->prev = NULL;
            if(index == 0){
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
                size++;
            }
            else if(index<0 || index>size){
                cout << "Invalid index!";
            }
            else{
                int cnt = 0;
                node*temp = head;
                while(cnt != index-1){
                    cnt++;
                    temp = temp->next;
                }
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                if (newNode->next != NULL)
                    newNode->next->prev = newNode; 
                size++;
            }
        }

        int front(){
            return head->data;
        }
        int back(){
            return tail->data;
        }
        int getIndex(int index){
            if(index>=size){
                return -1;
            }
            else if(index == 0){
                return head->data;
            }
            else{
            node *temp = head;
            int cnt =0;
            while(cnt!=index-1){
                temp = temp->next;
                cnt++;
            }
            return temp->next->data;
            }
        }

        void print(){
            node *temp = head;
            while(temp!=NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        void printReverse(){
            node *last = tail;
            while(last != NULL){
                cout << last->data << " ";
                last = last->prev;
            }
        }

        void pop_front(){
            node *temp = head;
            head = temp->next;
            head->prev = NULL;
            delete temp;
            size--;
        }   

        void pop_back(){
            node *last = tail;
            tail = last->prev;
            tail->next = NULL;
            delete last;
            size--;
        }

        void deleteIndex(int index){
            if(index == 0){
                node *temp = head;
                head = temp->next;
                delete temp;
                size--;
            }
            else if(index == size-1){
                node *last = tail;
                tail = last->prev;
                delete last;
                size--;
            }
            else if(index<0 || index>=size){
                cout << "Invalid index!";
            }
            else{
                node *temp = head;
                int cnt=-1;
                while(cnt!=index-1){
                    temp = temp->next;
                    cnt++;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                size--;
            }

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
};

int main(){
    listDouble l;
    l.push_front(5);
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(6);
    l.push_back(7);
    l.print();
    cout << endl;
    cout << "Size = "<<l.getSize() << endl;
    l.push_index(3, 9);
    l.push_index(2, 77);
    l.print();
    cout << "Size = "<<l.getSize() << endl;
    l.printReverse();
    cout << "Size = "<<l.getSize() << endl;
    l.pop_front();
    l.print();
    cout << endl;
    l.printReverse();
    cout << endl;
    cout << "Size = "<<l.getSize() << endl;
    l.pop_back();
    l.print();
    l.pop_back();
    l.pop_back();
    cout << endl;
    l.print();
    cout << endl;
    l.deleteIndex(2);
    l.print();
    cout << endl;
    l.printReverse();
    cout << endl;
    cout << "Size = "<<l.getSize() << endl;
    l.clear();
    cout << endl;
    l.print();
    cout << endl;
    l.printReverse();
    return 0;
}