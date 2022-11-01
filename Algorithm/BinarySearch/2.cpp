#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
    node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};


int main(){
    int a[] = {10, 8, 12, 5, 4, 12};
    int size = sizeof(a)/sizeof(int); // size of array
    cout << size;

    return 0;
}