#include <iostream>
using namespace std;

struct node
{
    int data;
    node * next;
};

class Linkedlist{
    private:
        node *head, *tail; 
    public:
        Linkedlist(){
            head = NULL;
            tail = NULL;
        }

        void add_end(int n){
            node *temp = new node();
            temp->data = n;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }

        void print(){
            node *temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

        void printReverse(){
            node* temp = tail;
            node* h = head;
        }
};

int main(){
    Linkedlist l;
    l.add_end(1);
    l.add_end(2);
    l.add_end(3);
    l.printReverse();
    return 0;
}