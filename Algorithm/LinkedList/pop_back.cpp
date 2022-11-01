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

        void pop_back(){
            node *temp = head;
            if(temp->link==NULL){
                head = NULL;
            }
            else{
                while(temp->link->link != NULL){
                    temp = temp->link;
                }
                delete temp->link;
                temp->link = NULL;
            }
        }

        void print(){
            node* temp = head;
            if(head == NULL){
                cout << "Empty!";
            }
            else{
            while(temp!=NULL){
                cout << temp->data << " ";
                temp = temp->link;
            }
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
    cout << endl;
    list.pop_back();
    list.print();
    cout << endl;
    list.pop_back();
    list.print();
    cout << endl;
    list.pop_back();
    list.print();
    cout << endl;
    list.push_back(7);
    list.push_back(8);
    list.print();
    cout << endl;
    list.pop_back();
    list.print();
    list.pop_back();
    cout << endl;
    list.print();
    list.pop_back();
    cout << endl;
    list.print();
    return 0;
}