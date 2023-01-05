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

int l(node *root){
    if(not root)return 0;
    return l(root->left)+1;
}

int r(node *root){
    if(not root)return 0;
    return r(root->right)+1;
}

map<int, int> m;
void tri(node *root){
    if(not root)return;
    // cout << l(root) << " " << r(root) << "\n";
    int mn = min(r(root), l(root));
    if(mn >= 2){
        // cout << "hey\n";
        for(int i = 2; i <= mn; i++){
            m[i]++;
        }
    }

    tri(root->left);
    tri(root->right);
   

}

void in(vector<int> &v , node*root){
    if(not root)return;
    in(v, root->left );
    v.push_back(root->val);
    in(v, root->right);
}

int main(){

    int n;scanf("%d", &n);
    int k = n;
    node *root=NULL;
    while(k--){
        int x;cin >> x;
        root = insert(root, x);
    }
    // map<int, int> m;
    for(int i = 2; i <= n; i++)m[i] = 0;
    tri(root);
    for(auto x : m){
        cout << x.second << ' ';
    }
    

}