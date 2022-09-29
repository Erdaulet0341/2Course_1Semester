#include <bits/stdc++.h>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node(string x){
        data = x;
        next = NULL;
    }
};

void fun(Node *head, int k){
    Node *temp = head;

}



int main(){
    int n,k;
    cin >> n >> k;
    Node *head, *temp;
    for(int i=0; i<n; i++){
        string x; cin >> x;
        if (i ==0){
            head = new Node(x);
            temp = head;
        }
        else{
            temp->next = new Node(x);
            temp = temp->next;
        }
    }

}