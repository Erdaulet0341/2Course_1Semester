#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node*left;
    node*right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

node *insert(node*data, int x){
    if(not data){
        return new node(x);
    }
    if(data->val > x)data->left =insert(data->left, x);
    else data->right = insert(data->right, x);
    return data;
}

int v = 0;
void leaves(node*data){
    if(not data)return;
    if(not data->left and not data->right)v++;

    leaves(data->left);
    leaves(data->right);
}


int main(){
    int n;cin >> n;
    node *data = NULL;
    while(n--){
        int x;cin >> x;
        data = insert(data, x);
    }
    leaves(data);
    cout << v;

    return 0;
}