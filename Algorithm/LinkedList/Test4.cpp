#include <iostream>
using namespace std;


struct node{
    int data;
    node * next;
};

class LinkedList{
    private:
        node * head;
    public:
        LinkedList(){
            head = NULL;
        }

        void push_front(int data){
            node * new1 = new node();
            new1->data = data;
            new1->next = head;
            head = new1;
        }

        void push_back(int data){
            node * new1 = new node();
            new1->data = data;
            new1->next = NULL;
            if(head ==  NULL){
                head = new1;
                head->next = NULL;
            }
            else{
                node * temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = new1;
            }
        }

        void print(){
            node *temp= head;
            while(temp!=NULL){
                cout << temp->data << " ";
                temp = temp->next;
            } 
        }



};


int main(){
    LinkedList ll;
    ll.push_back(-1);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.print();
    return 0;
}