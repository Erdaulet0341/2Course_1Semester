/*
///a
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

    node(int x){
        val = x;
        next = NULL;
    }
};

int MMM(node *head, int k){
    int mn = INT_MAX, ind = 0, i = 0;
    node * cur = head;
    while(cur){
        if(mn > abs(k-cur->val)){mn = abs(k-cur->val); ind = i;}
        cur = cur->next;
        i++;
    }

    return ind;
}

int main(){
    int n;cin >> n;
    node *head, *cur;
    int k;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        if(i == 0){
            head = new node(x);
            cur = head;
        }else{
            cur->next = new node(x);
            cur = cur->next;
        }
    }
    cin >> k;

    cout << MMM(head, k);

    return 0;
}

///b
#include <iostream>
using namespace std;

struct node {
	string word;
	node* next;


	node(string word) {
		this->word = word;
		this->next = NULL;
	}
};

// your code goes here

node* cyclicShift(node* head, int k) {
    // if(n)return;
    //    head                tail
//    ↓                   ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘

//           head        tail
//            ↓            ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘


//      tail  head
//        ↓   ↓
// ┌→ 1 → 3 → 5 → 7  →  9 → 11 ─┐
// └────────────────────────────┘

//       tail  head
//        ↓    ↓
// ┌→ 1 → 3    5 → 7 -> 9 → 11 ─┐
// └────────────────────────────┘
            node *tail = head;
            while(tail->next)tail = tail->next;
            tail->next = head;
            for(int i = 1; i < k; i++)head = head->next;
            tail = head;
            head = head->next;
            tail->next = NULL;
            // node* cur = head;
            // int cnt = 1;
            // while(cur->next and cnt < k){
            //     cur = cur->next;
            //     cnt++;
            // }

            // // if(not cur)return;
            // node* kth = cur;
            
            // while(cur->next)cur = cur->next;

            // cur->next = head;
            // head = kth->next;
            //kth->next = NULL;
            // node* p = head; node* q = head;
            // int cnt = 0;
            // node* prev;
            // while(p and cnt < k){
            //     prev = p;
            //     p = p->next;
            //     q = q->next;
            //     cnt++;
            // }
            // p = prev;
            // while(q){
            //     prev = q;
            //     q = q->next;
            // }
            // q = prev;

            // q->next = head;
            // head = p->next;
            // p->next = NULL;
    return head;
}


void print(node* head) {
	node* cur = head;
	while (cur != NULL) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	int k; cin >> k;
	node* head;
	node* cur;
	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		if (i == 0) {
			head = new node(word);
			cur = head;
		} else {
			cur->next = new node(word);
			cur = cur->next;
		}
	}

	head = cyclicShift(head, k);
	print(head);
}

///c
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    node(int x){
        val = x;
        next = NULL;
    }
};

void pr(node* root){
    while(root){
        cout << root->val << ' ';
        root=root->next;
    }
}

void del(node* head){
    while (head && head->next) {
    // Store a pointer to the item we're about to cut out
    node *tmp = head->next;
    // Skip the item we're cutting out
    head->next = head->next->next;
    // Prepare the head for the next iteration
    head = head->next;
    // Free the item that's no longer in the list
    free(tmp);
}
}
int main(){
    int n;cin >> n;
    node* head;
    node* cur;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(i == 0){
            head = new node(x);
            cur = head;
        }else{
            cur->next = new node(x);
            cur = cur->next;
        }

    }
    del(head);
    pr(head);
}


///d
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    
};

int maxDup(node *head){
    int mx_cnt = 0;
    node *tmp1 = head;
    while(tmp1){
        int cnt = 0;
        node *tmp2 = tmp1->next;
        while(tmp2){
            if(tmp1->val == tmp2->val)
                cnt++;
            tmp2 = tmp2->next;
        }

        if(mx_cnt < cnt){
            mx_cnt = cnt;
        }

        tmp1 = tmp1->next;
    }

    return mx_cnt;

}

vector<int> dups(node *head){
    int mx_cnt = maxDup(head);
    vector<int> v;
    node *tmp1 = head;
    while(tmp1){
        int cnt = 0;
        node *tmp2 = tmp1->next;
        while(tmp2){
            if(tmp1->val == tmp2->val)
                cnt++;
            tmp2 = tmp2->next;
        }

        if(mx_cnt == cnt){
            v.push_back(tmp1->val);
        }

        tmp1 = tmp1->next;
    }
    sort(v.rbegin(), v.rend());
    return v;

}


void print(node *head){
    while(head){
        cout << head->val << ' ';
        head = head->next;
    }cout << endl;
}

int main(){
    node *head;
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        node *newnode = new node();
        newnode->val = x;
        newnode->next = NULL;
        if(i == 0)head = newnode;
        else{
            node *cur = head;
            while(cur->next)cur = cur->next;
            cur->next = newnode;
        }
    }

    for(int i : dups(head)){
        cout << i << ' ';
    }

}


///e
#include <iostream>

using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
void removeDuplicates(Node* head)  
{  
    Node* tmp1 = head;
    Node *tmp2, *dup;
    while(tmp1 and tmp1->next){
        tmp2 = tmp1;
            if(tmp1->data == tmp2->next->data){
                dup = tmp2->next;
                tmp2->next = tmp2->next->next;
                delete dup;
            }else{
                tmp2 = tmp2->next;
                tmp1 = tmp1->next;
            }

    }
}  

int getCount(Node* head)  
{  
    int count = 0; 
    while(head){head = head->next;count++;}

    return count;  
}  

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;
}

///f
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    node(int x){
        val = x;
        next = NULL;
    }
};

void addPos(node* &head, int x, int pos){
    node* newnode = new node(x);
    if(pos == 0){
        newnode->next = head;
        head = newnode;
    }else{
        node* tmp = head;
        while(--pos > 0){
            tmp = tmp->next;
        }
        newnode->next = tmp->next;
        tmp->next = newnode;
    }
}

void pr(node* cur){
    while(cur){
        cout << cur->val << ' ';
        cur = cur->next;
    }
}

int main(){
    node* head;
    node* cur;
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(i == 0){
            head = new node(x);
            cur = head;
        }else{
            cur->next = new node(x);
            cur = cur->next;
        }

    }

    int val, pos;
    cin >> val >> pos;
    addPos(head, val, pos);
    pr(head);
}


///h
#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p){
    //write your code here 
    if(p == 0){
        node->next = head;
        head = node;
    }else{
        Node* tmp = head;
        while(--p > 0){
            tmp = tmp->next;
        }
        node->next = tmp->next;
        tmp->next = node;
    }

    return head;

}
 
Node* remove(Node* head, int p){
    //write your code here 
    Node* tmp1 = head;
    if(p == 0){
        head = tmp1->next;
        free(tmp1);
    }else{
        for(int i = 0; i < p-1; i++)tmp1 = tmp1->next;
        Node* tmp2 = tmp1->next;
        tmp1->next = tmp2->next;
        free(tmp2);
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    // write your code here 
    if(p1 == p2)return head;
    Node* cur = head;
    int a = 0, i = 0;
    while(true){
        if(i == p1){a = cur->val;break;}
        i++;cur = cur->next;
    }
    head = remove(head, p1);
    head = insert(head, new Node(a), p2);

    return head;
}
 
Node* reverse(Node* head){
    //write your code here 
    Node* prev = NULL;
    Node* cur = head;
    while(cur){
        Node* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp; 
    }

    return prev;
}
 
void print(Node* head){
    // write your code here 
    for(Node* cur = head; cur != NULL; cur = cur->next){
        cout << cur->val << ' ';
    }cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    //write your code here 
    
//   head                tail
//    ↓                   ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘

//           head        tail
//            ↓            ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘


//      tail  head
//        ↓   ↓
// ┌→ 1 → 3 → 5 → 7  →  9 → 11 ─┐
// └────────────────────────────┘

//       tail  head
//        ↓    ↓
// ┌→ 1 → 3    5 → 7 -> 9 → 11 ─┐
// └────────────────────────────┘
            Node *tail = head;
            while(tail->next)tail = tail->next;
            tail->next = head;
            for(int i = 1; i < x; i++)head = head->next;
            tail = head;
            head = head->next;
            tail->next = NULL;
            return head;
}
 

Node* cyclic_right(Node* head, int x){

//    head                tail
//    ↓                   ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘

//                head    tail
//                ↓       ↓
// ┌→ 1 → 3 → 5 → 7 → 9 → 11 ─┐
// └──────────────────────────┘


//                tail  head
//                ↓     ↓
// ┌→ 1 → 3 → 5 → 7  →  9 → 11 ─┐
// └────────────────────────────┘

//                tail  head
//                ↓     ↓
// ┌→ 1 → 3 → 5 → 7     9 → 11 ─┐
// └────────────────────────────┘


Node *tail = head;
int sz = 0;
while(tail->next){
    sz++;
    tail = tail->next;
}

tail->next = head;
for(int i = 0; i < sz-x; i++){
    head = head->next;
}


tail = head;
head = head->next;
tail->next = NULL;


return head;
}
 
int main(){
    Node* head = NULL;
    int command;
    // head = insert(head, new Node(0), 0);
    // head = insert(head, new Node(1), 1);
    // head = insert(head, new Node(2), 2);

    // print(head);
    while (cin >> command)
    {
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}

///i
#include <bits/stdc++.h>
  
using namespace std;

struct node{
	string word;
	node* next;
	node* prev;
	node(string w){
		word = w;
		next = NULL;
		prev = NULL;
	}
};

node* head = NULL;
node* tail = NULL;
void add_front(string s){
			node* newnode = new node(s);
			if(not tail){head = newnode;tail = newnode;}
			else{
				head->prev = newnode;
				newnode->next = head;
				head = newnode;
			}
}

void add_back(string s){
			node* newnode = new node(s);
			if(not head){tail = newnode;head = newnode;}
			else{
				newnode->prev = tail;
				tail->next = newnode;
				tail = newnode;
			}
}

void erase_front(){
    
        if (head->next != NULL) {
            head->next->prev = NULL;
        }
        node* next = head->next;
        free(head);
        head = next;
    		
}

void erase_back(){
    
        if (tail->prev != NULL) {
            tail->prev->next = NULL;
        }
        node* prev = tail->prev;
        tail->prev = NULL;
        free(tail);
        tail = prev;
				
    
}

string front(){
	return head->word;
}

string back(){
	return tail->word;
}

void clear(){
	node* tmp = head;
	while(head){
		tmp = head;
		head = head->next;
		free(tmp);
	}	
}

bool empty(){
	return head == NULL or tail == NULL;
}



int main()
{
	
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
				// cout << "here\n";
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
		if(s == "empty")cout << empty();
   		// cout << "hi" << endl;
   	}
    return 0;
}

///k
#include <bits/stdc++.h>
using namespace std;

struct node{
    char val;
    node *next;
    node(char x){
        val = x;
        next = NULL;
    }
};



void pr(node *&head){
    node *cur = head;
    while(cur){
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
}

int once(node *head){
   unordered_map<int, int> mp;
   for (node *temp=head; temp!=NULL; temp=temp->next){
      mp[temp->val]++;
   }
   for (node *temp=head; temp!=NULL; temp=temp->next){
      if (mp[temp->val] == 1){
         return temp->val;
      }
   }
   return -1;
}
int main(){
    int n;cin >> n;
    while(n--){
        node *head, *cur;
        int x;cin >> x;
        int s = 0;
        for(int i = 0; i < x; i++){
            char c;cin >> c;
            bool ok = false;
            if(i == 0){
                head = new node(c);
                cur = head;
            }else{
                cur->next = new node(c);
                cur = cur->next;
            }
            if(once(head) != -1)
                cout << char(once(head)) << ' ';
            else cout << -1 << ' ';
        }
        cout << endl;
    }

    return 0;
}

///l
# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
  // Implement this function
    int mx = -20000, curm = 0;
    Node* tmp = head;
    while(tmp){
        curm += tmp->val;
        if(mx < curm)mx = curm;
        if(curm < 0)curm = 0;
        tmp = tmp->next;
    }

    return  mx;
	
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}



*/