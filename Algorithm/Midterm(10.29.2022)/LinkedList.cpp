#include <iostream>
using namespace std;

struct node{
    int data;
    node * next;
};

class Linked_List{
    private:
        node * head;
    public:
        Linked_List(){
            head = NULL;
        }  

        void push_front(int x){
            node *new1 = new node();
            new1->data = x;
            new1->next = head;
            head = new1;
        }
        
        void push_back(int x){
            node * new1 = new node();
            new1->data = x;
            new1->next = NULL;
            if (head == NULL){
                head = new1;
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
            node * temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

};  

int main(){

    Linked_List lc;
    lc.push_back(1);
    lc.push_back(2);
    lc.push_back(3);
    lc.push_front(-1);
    lc.print();

    return 0;
}