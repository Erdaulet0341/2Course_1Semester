#include <iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;

    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

node * insert(node *n, int data){
    if(n == NULL){
        n = new node(data);
        return n;
    }
    if(n->data<data){
        n->right = insert(n->right, data);
    }
    else{
        n->left = insert(n->left, data);
    }
    return n;
}

bool search(node *n, int x){
    if(n == NULL){
        return false;
    }
    if(n->data<x){
        search(n->right, x);
    }
    else if(n->data>x){
        search(n->left, x);
    }
    else{
        return true;
    }
}

int degree(int n){
    int sum = 1;
    for(int i=0; i<n; i++){
        sum*=2;
    }
    return sum;
}

node * min(node *n){
    node *temp = n;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

node * max(node *n){
    node *temp = n;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}
int cnt=0;
int count(node *n){
    if(n==NULL){
        return cnt;
    }
    if(n->left != NULL and n->right != NULL){
        cnt++;
    }
    count(n->left);
    count(n->right);
}

void preorder(node *n){
    if(n!=NULL){
        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }

}

void inorder(node * n){
    if(n!=NULL){
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
}


int main(){

    node * root = NULL;
    int n;
    cin >> n;
    for(int i=0; i<degree(n)-1; i++){
        int x; cin >> x;
        root = insert(root, x);
    }
    preorder(root);
    return 0;
}