#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void PrintLinkedList(Node* head){
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

void InsertFront(Node**head, int num){
    // preapare new Node
    Node* newNode = new Node();
    newNode->data = num;
    //put new Node at the front of linkedList
    newNode->next = *head;
    //move head of the linkedlist to point the new Node; 
    *head = newNode;
}


void InsertEnd(Node**head, int num){
    //1) Prepare new Node
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = NULL;
    //2) If linkedList is empty , newNode will be a head of Node;
    if (*head == NULL){
        *head = newNode;
        return;
    } 
    //3) Find the last node;
    Node* last = *head; 
    while(last->next != NULL){
        last = last->next;
    } 
    //4) Insert newNode after last Node (at the end of LinkedList);
    last->next = newNode;
}

void InsertAnyPlace(Node * previous, int num){
    //1) Check if previous node not NULL
    if (previous == NULL){
        cout << "Previuos can not be NULL";
        return;
    }
    //2)Prepare a new node;
    Node* newNode = new Node();
    newNode->data = num;
    //3) Insert new node after previous;
    newNode->next = previous->next;
    previous->next = newNode;
}

int main(){
    Node* head = new Node();
    Node* middle = new Node();
    Node* last = new Node();

    head->data = 1;
    head->next = middle;
    middle->data = 2;
    middle->next = last;
    last->data = 3;
    last->next = NULL;
    InsertFront(&head, -1);
    InsertFront(&head, -2);
    InsertEnd(&head, 4);
    InsertAnyPlace(middle, 9);

    PrintLinkedList(head);

    return 0;
}