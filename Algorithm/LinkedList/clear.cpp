#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* link;
};
class LinkedList{
    private:
        node *head;
        int size;
    public:
        LinkedList(){
            head = NULL;
        }

        void push_front(int x){
            node *newNode = new node();
            newNode->data = x;
            newNode->link = NULL; /// 1 2 
            newNode->link = head;
            head = newNode;
            size++;
        }

        void clear(){
            node *temp = NULL;
            node *cur = head;
            while(cur != NULL){
                temp = cur->link;
                delete cur;
                cur = temp;
            }
            head = NULL;
        }

        void print(){
            if(head == NULL){
                cout << "Empty!"<< endl;
            }
            node* temp = head;
            while(temp!=NULL){
                cout << temp->data << " ";
                temp = temp->link;
            }
        }
};

int main(){
    LinkedList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(20);
    list.print();
    list.clear();
    list.print();
    return 0;
}