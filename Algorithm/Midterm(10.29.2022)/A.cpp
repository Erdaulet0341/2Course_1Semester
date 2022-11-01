#include <bits/stdc++.h> 
using namespace std; 
 
struct node{ 
    int val; 
    node *left; 
    node *right; 
 
    node(int x){ 
        val = x; 
        left = NULL; 
        right = NULL; 
    } 
}; 
 
node *insert(node *root, int n){ 
    if(root == NULL){ 
        root = new node(n); 
        return root; 
    } 
    if(n > root->val)
        root->right = insert(root->right, n); 
    else 
        root->left = insert(root->left, n); 
 
    return root; 
     
} 
 
int left(node *root){ 
    if(root == NULL)return 0; 
    return left(root->left)+1; 
} 
 
int right(node *root){ 
    if(root == NULL)return 0; 
    return right(root->right)+1; 
} 
 
map<int, int> m; 

void tree(node *root){ 
    if(root == NULL)return; 
    int mn = min(left(root), right(root)); 
    if(mn >= 2){ 
        for(int i = 2; i <= mn; i++)
            m[i]++; 
    } 
    tree(root->left); 
    tree(root->right); 
} 
 
 
int main(){ 
    int n;
    cin >> n; 
    node *root = NULL; 
    for(int i = 2; i <= n; i++){
        m[i] = 0; 
    }

    for(int i = 0; i < n; i++){ 
        int x;
        cin >> x; 
        root = insert(root, x); 
    } 
 
    tree(root); 
 
    for(int i = 2; i <= n; i++)
        cout << m[i] << " "; 
}