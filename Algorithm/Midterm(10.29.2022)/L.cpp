#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int d){
        this->data = d;
        this->left = this->right = NULL;
    }
};

node * add(node *n, int x){
    if(n == NULL){
        n = new node(x);
        return n;
    }
    if(n->data < x){
        n->right = add(n->right, x);
    }
    else{
        n->left = add(n->left, x);
    }
    return n;
}

void inorder(node * n){
    if(n != NULL){
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
}
int cnt=0;
int leaf(node * n){
    if(n == NULL){
        return cnt;
    }
    if(n->right==NULL and n->left==NULL){
        cnt++;
    }
    leaf(n->left);
    leaf(n->right);
}

int main(){
    node * root = NULL;
    int n; 
    cin >> n;

    for(int i=0; i<n; i++){
        int x; cin >> x;
        root = add(root, x);
    }

    cout << leaf(root);

    return 0;
}