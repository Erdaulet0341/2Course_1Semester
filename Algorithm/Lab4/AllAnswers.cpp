/*
////    a
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct BST{
node *root;

BST(){
    root = NULL;
}
node *insert(node *root, int x){
    if(not root){
        root = new node(x);
        return root;
    }
    if(x > root->val)root->right = insert(root->right, x);
    else root->left = insert(root->left, x);

    return root;
}

bool check(node *root, string s){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'L'){
            if(not root->left)break;
            else root = root->left;
        }else if(s[i] == 'R'){
            if(not root->right)break;
            else root = root->right;
        }
        cnt++;
    }

    if(cnt == s.size())return true;
    return false;
}
};

int main(){
    BST bst;
    int n, m;
    // node *root = NULL;
    cin >> n >> m;
    while(n--){
        int x;cin >> x;
        bst.root = bst.insert(bst.root, x);
    }
    while(m--){
        string s;
        cin >> s;
        cout << (bst.check(bst.root, s) ? "YES\n" : "NO\n");
    }
}


////    b
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

node *insert(node *root, int x){
    if(not root){
        root = new node(x);
        return root;
    }
    if(x > root->val){
        root->right = insert(root->right, x);
    }else{
        root->left = insert(root->left, x);
    }

    return root;

}

int size(node *head){
    node *root = head;
    if(not root)return 0;
    return 1 + size(root->left) + size(root->right);
}

int solve(node *root, int x){
    if(root->val == x)return size(root);
    else if(root->val > x)return solve(root->left, x);
    else return solve(root->right, x);
    // return -1;
}

int main(){
    int n;cin >> n;
    node *root = NULL;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        root = insert(root, x);
    }
    int x;cin >> x;
    cout << solve(root, x);
}


////    c
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

node *insert(node*root, int x){
    if(not root){
        root = new node(x);
        return root;
    }
    if(root->val > x){
        root->left = insert(root->left, x);
    }else root->right = insert(root->right, x);

    return root;
}

void find(node *&root, int x){
    while(root){
        if(root->val == x)return;
        else if(root->val > x)root = root->left;
        else root = root->right;
    }
}

void pre(vector<int> &v, node *root){
    if(not root)return;
    v.push_back(root->val);
    pre(v, root->left);
    pre(v, root->right);
}

int main(){
    int n;cin >> n;
    node *root = NULL;
    while(n--){
        int x;cin >> x;
        root = insert(root, x);
    }
    int k;cin >> k;
    vector<int> v;
    find(root, k);
    pre(v, root);
    for(int x:v)cout << x << ' ';
}

////    d
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root, int x){
    if(not root){
        root = new node(x);
        return root;
    }
    if(root->val < x)root->right = insert(root->right, x);
    else root->left = insert(root->left, x);

    return root;
}

int h(node *root){
    if(not root)return 0;
    return 1 + max(h(root->left), h(root->right));
}

void sum(vector<int> &v, node *root, int level){
    if(not root)return;

    v[level] += root->val;

    sum(v, root->left, level+1);
    sum(v, root->right, level+1);
}

int main(){
    int n;cin >> n;
    node *root = NULL;
    for(int i  =0; i < n; i++){
        int x;cin >> x;
        root = insert(root, x);
    }

    vector<int> v;
    for(int i = 0; i < h(root); i++)v.push_back(0);
    sum(v, root, 0);

    cout << v.size()<< endl;
    for(int x:v)cout << x << ' ';
}


////    e
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

int height(node *root){
    if(not root)return 0;
    int l = height(root->left), r = height(root->right);
    return 1 + max(l, r);
}

int widthOfBinaryTree(node* root, int lvl) {
        if(root == NULL)
            return 0;
        if(lvl == 1)return 1;

        return widthOfBinaryTree(root->left, lvl-1) + widthOfBinaryTree(root->right, lvl-1);
}
        
int getMax(node *root){
    int mx = 0;
    for(int i = 1; i <= height(root); i++){
        mx = max(mx, widthOfBinaryTree(root, i));
    }

    return mx;
}

node *insert(node *root, int x, int y, int z){
    if(not root){
        root = new node(y);
        return root;
    }
    if(root->val == x){
        if(z == 0){
            root->left = insert(root->left, x, y, z);
        }else{
            root->right = insert(root->right, x, y, z);
        }
    }

    insert(root->left, x, y, z);
    insert(root->right, x, y, z);

    return root;
}

int main(){
    int n;cin >> n;
    n--;
    node *root = new node(1);
    while(n--){
        int x, y, z;
        cin >> x >> y >> z;
        root = insert(root, x, y, z);
    }

    cout << getMax(root);

}


////    f
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }

};

node *insert(node *root, int x){
    if(not root){
        root = new node(x);
        return root;
    }
    if(x > root->val){
        root->right = insert(root->right, x);
    }else root->left = insert(root->left, x);

    return root;
}

int cnt = 0;
void tri(node *root){
    if(not root)return;
    if(root->right and root->left)cnt++;
    tri(root->left);
    tri(root->right);
}

int main(){
    int n;cin >> n;
    node *root = NULL;
    while(n--){
        int x; cin >> x;
        root = insert(root, x);
    }
    tri(root);

    cout << cnt;
}


////    g
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
int mx = 0;
class BST{ 
private: 
    node * root; 
    node * push(node *cur, int val){ 
        if(cur == NULL) return new node(val); 
        if(val > cur->val) cur->right = push(cur->right, val); 
        if(val < cur->val) cur->left = push(cur->left, val); 
        return cur; 
    } 
 
    int height(node * cur){ 
        if(cur == NULL) return 0; 
        return 1 + max(height(cur->left), height(cur->right)); 
    } 
 
    void find(node * cur){ 
        if(cur != NULL){ 
            if(height(cur->left)+height(cur->right)+1 > mx ) mx = height(cur->left)+height(cur->right)+1;  
            find(cur->left); 
            find(cur->right); 
        } 
    } 
 
 
 
public: 
    BST(){ 
        root = NULL; 
    } 
 
    void push(int val){ 
        root = push(root, val); 
    } 
    void find(){ 
        find(root); 
    } 
}; 
 
 
 
int main(){ 
    BST tree; 
    int n, x; 
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        int t; 
        cin >> t; 
        tree.push(t); 
    } 
    tree.find(); 
    cout << mx; 
    return 0; 
}


////    h
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x){
        val =x;
        left = NULL;
        right = NULL;
    }
};
int sum = 0;

    node *insert(node *cur, int x){
        if(not cur){
            cur = new node(x);
            return cur;
        }
        if(x > cur->val)cur->right = insert(cur->right, x);
        else cur->left = insert(cur->left, x);

        return cur;
    }
    void greaterSum(node *&cur){
        if(cur){
            if(cur->right)greaterSum(cur->right);
            sum += cur->val;
            cur->val = sum;
            if(cur->left)greaterSum(cur->left);
        }
        return;
    }

    void in(node *cur, vector<int> &v){
        if(not cur)return;
        in(cur->right, v);
        v.push_back(cur->val);
        in(cur->left, v);
    }




int main(){
    node *root = NULL;
    int n;cin >> n;
    while(n--){
        int x;cin >> x;
        root = insert(root, x);
    }
    vector<int>v;
    greaterSum(root);
    in(root, v);
    for(int x:v)cout << x << ' ';
}


////    i
#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int val;
    int count;
    struct node *left, *right;
};
 
struct node *newNode(int item)
{
    struct node *temp = new node();
    temp->val = item;
    temp->left = temp->right = NULL;
    temp->count = 1;
    return temp;
}
 
bool find(node *current, int x){
	if(current == NULL)
		return false;
	
	if(x > current->val) return find(current->right, x);
	else if(x < current->val) return find(current->left, x);
	return true;
} 


void inorder(struct node *root, int x)
{
    if (root != NULL)
    {
        if(x == root->val){
            cout << root->count << endl;
            return;
        }
        inorder(root->left, x);
        
        inorder(root->right, x);
    }
}
 
struct node* insert(struct node* node, int val)
{
    if (node == NULL) return newNode(val);
 
    if (val == node->val)
    {
    (node->count)++;
        return node;
    }
 
    if (val < node->val)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);
 
    return node;
}
 
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
struct node* deleteNode(struct node* root,
                                 int val)
{
    if (root == NULL) return root;
 
    if (val < root->val)
        root->left = deleteNode(root->left, val);
 
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
 
    else
    {
        if (root->count > 1)
        {
            (root->count)--;
            return root;
        }
 
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = minValueNode(root->right);
 
        root->val = temp->val;
        root->count = temp->count;
       
          temp->count = 0;
 
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main(){
    node* root = NULL;
    int n;cin >> n;
    while(n--){
        string s;cin >> s;
        if(s == "insert"){
            int x; cin >> x;
            root = insert(root, x);
        }else if(s == "delete"){
            int x;cin >> x;
            root = deleteNode(root, x);
        }
        else if(s == "cnt"){
            int x;cin >> x;
            if(find(root, x))
                inorder(root, x);
            else cout << 0 << endl;
        }
    }


}


////    j
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
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

void in(vector<node*> &v, node *root){
    if(root){
        in(v, root->left);
        v.push_back(root);
        in(v, root->right);
    }
}

node *BSTtoBal(vector<node*> &v, int l, int r){
    if(l > r)return NULL;
    int m = (r+l)/2;
    node *root = v[m];

    root->left = BSTtoBal(v, l, m-1);
    root->right = BSTtoBal(v, m+1, r);

    return root;
}

node *newTree(node *root){
    vector<node*> v;
    in(v, root);

    return BSTtoBal(v, 0, v.size()-1);
}

void pre(node *root){
    if(not root)return;
    cout << root->val << ' ';
    pre(root->left);
    pre(root->right);
}



int main(){
    node *root = NULL;
    int n;cin >> n;
    int sz = pow(2, n) -1;
    while(sz--){
        int x;cin >> x;
        root = insert(root, x);
    }

    root = newTree(root);
    pre(root);
}
*/