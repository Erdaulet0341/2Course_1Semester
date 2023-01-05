#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
    node(){};
    node(int x){
        val = x;
        right = nullptr;
        left = nullptr;
    }
};

node *insert(node *root, int x){
    if(not root){
        root = new node(x);
        return root;
    }
    if(x > root->val)root->right = insert(root->right, x);
    else root->left = insert(root->left, x);
    
    return root;
}

int sum = 0;
void s(node *root, int lvl){
    if(not root)return;
    sum += (root->val - lvl);
    s(root->left, lvl+1);
    s(root->right, lvl+1);
}

int main(){
    int n;cin >> n;
    node*root = NULL;
    while(n--){
        int x;cin >> x;
        root = insert(root,x);
    }

    s(root, 0);
    cout << sum;
}