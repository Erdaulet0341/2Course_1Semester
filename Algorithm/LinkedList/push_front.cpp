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

        void print(){
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
    return 0;
}