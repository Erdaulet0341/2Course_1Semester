#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class LiinkedList{
    private:
        node *head, *tail;
    public:
        LiinkedList(){
            head = NULL;
            tail = NULL;
        }

        void end(int n){
            node *tmp = new node;
            tmp->data = n;
            tmp->next = NULL;
            if(head == NULL){
                tail = tmp;
                head = tmp;
            }
            else{
                tail->next = tmp;
                tail = tail->next;
            }
        }

        void display(){
            node *tmp;
            tmp = head;
            while(tmp != NULL){
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }

        void front(int n){
            node *tmp = new  node();
            tmp->data = n;
            tmp->next = head;
            head = tmp;
        }

        void deletee(int n){
            node *tmp;
            if(head->data==n){
                tmp = head;
                head = head->next;
                delete tmp;
            }
            else{
                node *cur = head;
                while(cur->next != NULL){
                    if(cur->next->data == n){
                        tmp = cur->next;
                        cur->next = cur->next->next;
                        delete tmp;
                    }
                    else{
                        cur = cur->next;
                    }
                }
            }
        }
};

int main(){
    LiinkedList a;
    a.front(3);
    a.front(4);
    a.display();
    a.deletee(2);
    cout << endl;
    a.display();
    return 0;      
}