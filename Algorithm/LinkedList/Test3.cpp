#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * link;
};
int size = 0;

class  LinkeadLIst
{
private:
    node * head;
public:
    LinkeadLIst(){
        head = NULL;
    }
    int getSize(){
        return size;
    }
    int getIndex(int index){
        if(head == NULL){
            cout << "List is empty";
        }
        else if(index<0 || index>size-1){
            cout << "Invalid index!";
            return -1;
        }
        else if(index == 0){
            return head->data;
        }
        else{
            int cnt = 0;
            node *temp = head;
            while(cnt != index-1){
                temp = temp->link;
                cnt++;
            }
            return temp->link->data;
        }
    }

    void push_front(int x){
        node *newNode = new node();
        newNode->data = x;
        newNode->link = head;
        head = newNode;
        size++;
    }
    void push_back(int x){
        node *newNode = new node();
        newNode->data = x;
        newNode->link =NULL;
        if(head == NULL){
            head = newNode;
            head->link = NULL;
        }
        else{
            node *temp = head;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = newNode;
        }
        size++;
    }
    void pop_front(){
        node *temp = head;
        head = temp->link;
        delete temp;
    }
    void push_index(int index, int data){
        node *newNode = new node();
        newNode->data = data;
        newNode->link =NULL;
        if(index<0 || index>size){
            cout << "Invalid index!";
        }
        else if (index == 0){
            newNode->link = head;
            head = newNode;
            size++;
        }
        else if(head == NULL){
            cout << "List is empty!";
        }
        else{
            node *temp = head;
            int cnt = 0;
            while(cnt!=index-1){
                temp = temp->link;
                cnt++;
            }
            newNode->link = temp->link;
            temp->link = newNode;
            size++;
        }
    }
    void pop_back(){
        if(head == NULL){
            cout << "List is empty!";
        }
        else if(head->link == NULL){
            head = NULL;
        }
        else{
            node *temp = head;
            while(temp->link->link != NULL){
                temp = temp->link;
            }
            delete temp->link;
            temp->link = NULL;
        }
    }

    void print(){
        node *temp = head;
        if(head == NULL) cout << "List is empty!";
        else while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->link;
        }
    }

    void deleteIndex(int index){
        if(index == 0){
            node* temp = head;
            head = temp->link;
            delete temp;
        }
        else if(index<0 || index>=size){
            cout << "Invalid index!";
        }
        else if(head == NULL){
            cout << "List is empty!";
        }
        else{
            node * temp = head;
            int cnt = 0;
            while(cnt != index-1){
                cnt++;
                temp = temp->link;
            }
            temp->link = temp->link->link;
        }
    }

    void reverse(){
        node *temp = NULL;
        node *prev = NULL;
        node *current = head;
        while(current != NULL) {
            temp = current->link;
            current->link = prev;
            prev = current;
            current = temp;
        }
        head = prev;
    }
};


int main(){
    LinkeadLIst l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    for(int i=0; i<l.getSize(); i++){
        cout << l.getIndex(i) << " ";
    }
    cout << endl;
    l.deleteIndex(5);
    l.print();
    
    return 0;
}