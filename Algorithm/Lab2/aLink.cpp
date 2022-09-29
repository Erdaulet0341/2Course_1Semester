#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

int absMin(Node * head, int k){
    Node * temp = head;
    int min = 1e9;
    int i =0, index = 0;
    while(temp){
        if (min>abs(temp->data-k)){
            min = abs(temp->data - k);  
            index = i; 
        }
        temp = temp->next;
        i++;
    }
    return index;
}

int main(){
    Node *head, *temp;
    int n, k; cin>>n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        if (i ==0){
            head = new Node(x);
            temp = head;
        }
        else{
            temp->next = new Node(x);
            temp = temp->next;
        }
    }
    cin >> k;
    cout << absMin(head, k);
}