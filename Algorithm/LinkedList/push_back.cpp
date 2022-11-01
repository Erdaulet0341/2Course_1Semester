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

        void push_back(int x){
            node *newNode = new node();
            newNode->data = x;
            newNode->link = NULL;
            if(head == NULL){
                head = newNode;
                head->link = NULL;
            }
            else{
                node *cur = head;
                while(cur->link != NULL){
                    cur = cur->link;
                }
                cur->link = newNode;
            }
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
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.print();
    return 0;
}