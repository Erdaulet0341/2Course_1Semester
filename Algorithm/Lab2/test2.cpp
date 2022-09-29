#include <iostream>
using namespace std;

struct Node{
    int num;
    Node* next;
};

bool isEmpty(Node * head);
char menu();
void insertAsFirstElement(Node *&first, Node *&last, int value);
void insert(Node *&first, Node *&last, int value);
void remove(Node*&first, Node *&last);
void showList(Node* current);

bool isEmpty(Node * head){
    if (head == NULL) return true;
    else return false;
}
char menu(){
    char coice;
    cout << "Menu\n";
    cout << "1. Add an item\n";
    cout << "2. Remove an item\n";
    cout << "3. Show the list\n";
    cout << "4. Exit\n";

    cin >> coice;
    return coice; 
}
void insertAsFirstElement(Node *&head, Node *&last, int value){
    Node *temp = new Node();
    temp->num = value;
    temp->next = NULL;
    head = temp; 
    last = temp;  
}
void insert(Node *&head, Node *&last, int value){
    if (isEmpty(head)) insertAsFirstElement(head,last, value);
    else{
        Node *temp = new Node();
        temp->num = value;
        temp->next = NULL;
        last->next = temp;  
        last = temp;
    }
}
void remove(Node*&head, Node *&last){
    if(isEmpty(head)) cout << "Empty" << endl;
    else if(head == last){
        delete head;
        head = NULL;
        last = NULL;
    }
    else{
        Node * temp = head;
        head = head->next;
        delete temp; 
    }
}
void showList(Node* current){
    if (isEmpty(current)) cout << "The list is empty" << endl;
    else{
        cout << "The list is contains " << endl;
        while (current != NULL){
            cout << current->num << " " << endl;
            current = current->next;
        }
    }
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    char coice;
    int number;

    do{
        coice  = menu();
        switch(coice){
            case '1':
                cout << "Enter the number to be inserted: ";
                cin >> number;
                insert(head,tail, number);
                break;
            case '2': remove(head, tail); break;
            case '3': showList(head); break;
            default : cout << "System exits!";  
        }

    }while(coice != '4');

    return 0;
}