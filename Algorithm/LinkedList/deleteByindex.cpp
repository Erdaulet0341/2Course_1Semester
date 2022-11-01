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

        void deleteByIndex(int index){
            node *temp = head;
            int cnt=0;
            if(index>=size-1){
                cout << "Invalid index!" << endl;
            }
            else if(size == 1){
                head = NULL;
            }
            else if(index == 0){
                head = temp->link;
                delete temp;
            }
            else{
                while(cnt != index-1){
                    temp = temp->link; /// 1 2 3
                    cnt++;
                }
                temp->link = temp->link->link;
            }
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
    list.print();
    list.deleteByIndex(0);
    cout << endl;
    list.print();
    return 0;
}