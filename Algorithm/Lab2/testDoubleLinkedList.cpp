#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void printFoward(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void printBackward(Node* tail){
    Node* temp = tail;
    while(temp!= NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

int main(){
    Node* head;
    Node* tail;
    
    //add 1st node to doublelist
    Node* node = new Node;
    node->data = 1;
    node->next = NULL;
    node->prev = NULL;
    head = node;
    tail = node;

    //add 2nd node to doublelist
    node = new Node;
    node->data = 2;
    node->next = NULL;
    node->prev = tail;
    tail->next = node;
    tail = node;

    //add 3rd node to doublelist
    node = new Node;
    node->data = 3;
    node->next = NULL;
    node->prev = tail;
    tail->next = node;
    tail = node;

    printFoward(head);
    cout << "\n" << "--------------------------------" << endl;
    printBackward(tail);
}