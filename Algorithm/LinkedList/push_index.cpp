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

        void push_index(int index, int x){
            node *newNode = new node();
            newNode->data = x;
            newNode->link = NULL; /// 1 2 
            if(index<0 || index>size-1){
                cout << "Invalid index!" << endl;
            }
            else if(index==0){
                newNode->link = head;
                head = newNode;
            }
            else{  
                int cnt = 0;
                node *cur = head;
                while(cnt != index-1){
                    cnt++;
                    cur = cur->link;
                }
                newNode->link = cur->link;
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
    list.push_index(0,1);
    list.push_index(1,2);
    list.push_index(2,3);
    list.push_index(0,3);
    list.push_index(4,7);
    list.push_index(6,9);
    list.print();
    return 0;
}