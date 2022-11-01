#include <iostream>
using namespace std;

class BST{
    struct node{
        int data;
        node *left;
        node *right;
    };

    node* insert(int data, node *temp){
        if (temp == NULL){
            temp = new  node();
            temp->data = data;
            temp->right = temp->left = NULL;
        }
        else if(data < temp->data){
            temp->left = insert(data, temp->left);
        }
        else if(data > temp->data){
            temp->right = insert(data, temp->right);
        }
        return temp;
    }
    void inorder(node *temp){
        if (temp == NULL){
            return;
        }
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
    void preorder(node *temp){
        if (temp == NULL){
            return;
        }
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void postorder(node *temp){
        if(temp == NULL){
            return;
        }
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
    void print2DUtil(node* root, int space)
        {
            if (root == NULL)
                return;
            space += 5;
            print2DUtil(root->right, space);
            cout << endl;
            for (int i = 5; i < space; i++)
                cout << " ";
            cout << root->data << "\n";
            print2DUtil(root->left, space);
        }
    void print2D(node* root)
    {
        print2DUtil(root, 0);
    }

    public:
        node *root;
        BST() {
            root = NULL;
        }
        void insert(int x){
            root = insert(x, root);
        }
        void displayInorder(){
            inorder(root);
            cout << endl;
        }
        void displayPreorder(){
            preorder(root);
            cout << endl;
        }
        void displayPostorder(){
            postorder(root);
            cout << endl;
        }

        void in2D(){
            print2D(root);
        }

};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        tree.insert(x);
    }
    int x; cin >> x;
    tree.in2D();
    return 0;
}
