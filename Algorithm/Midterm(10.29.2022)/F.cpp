#include <iostream>
#include <map>
using namespace std;

map<int,int> m;

struct node
{
    int data;
    node * left;
    node * right;
    node(int n){
        this->data = n;
        this->left = this->right= NULL;
    }
};

node * insert(node * n,int data){
    if(n == NULL){
        n = new node(data);
        return n;
    }
    if(n->data < data)
        n->right = insert(n->right, data);
    else
        n->left = insert(n->left, data);
    return n;
}


int h(node * n){
    if(n==NULL) return 0;
    int l=h(n->left);
    int r=h(n->right);
    return max(l,r)+1;
}

int ans(node * n,int level){
    if(n==NULL) return level;
    m[n->data]=level;
    return max(ans(n->left,level+1),ans(n->right,level+1));
}

void inorder(node *n){
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
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        root = insert(root, x);
    }
    ans(root,0);
    map<int,int> :: iterator it;
    int sum=0;
    for(it=m.begin();it!=m.end();it++){
        sum+=it->first-it->second;
    }
    cout<<sum;

    return 0;
}