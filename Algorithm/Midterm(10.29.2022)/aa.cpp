/**
 * a)
 #include<iostream>
#include<map>
using namespace std;
struct Node{
    int val;
    Node * right;
    Node * left;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
map<int,int> mp;
Node * add(Node * cur, int val){
    if(cur==NULL) return new Node(val);

    else if(cur->val<val){
        cur->right=add(cur->right,val);
    }

    else if(cur->val>val){
        cur->left=add(cur->left,val);
    }
    return cur;
}

void height(Node * cur) {
    Node * temp = cur;
    int l = 0, r = 0;
    while(temp != NULL) {
        temp = temp -> left;
        l++;
    }

    temp = cur;
    while(temp != NULL) {
        temp = temp -> right;
        r++;
    } 

    for(int i = 1; i <= min(l, r); ++i) {
        mp[i]++;
    }
}
 void count(Node * cur){
    if(cur!=NULL){
        count(cur->left);
        count(cur->right);
        height(cur);
    }
}
int main(){
    int n; cin>>n;
    int x;
    Node * root=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        root=add(root,x);
    }
    count(root);
    for(int k=2;k<=n;k++){
        cout<<mp[k]<<" ";
    }
}



    b)
//Решето Эратосфена- прайм числа
#include<iostream>
using namespace std;
bool SieveOfEratosphenes(int n, bool IsPrime[]){
    IsPrime[0]=IsPrime[1]=false;
    for(int i=2;i<=n;i++){
        IsPrime[i]=true;
    }
    for(int p=2;p*p<=n;p++){
        if(IsPrime[p]){
            for(int i=p*p;i<=n;i+=p) IsPrime[i]=false;
        }
    }
}
void solve(int n){
    bool IsPrime[n+1];
    SieveOfEratosphenes(n,IsPrime);

    for(int i=0;i<n;i++){
        if(IsPrime[i] and IsPrime[n-i]){
            cout<<i<<" "<<n-i;
            return;
        }
    }
}



int main(){
    int n; cin>>n;
    solve(n);

}

    c)
//UPDATE HEAP TASK
#include<iostream>
using namespace std;
#define N 100001

struct Heap{
    int val[N];
    int hs;
    
    Heap(){
        hs=0;
    }

    int getMax(){
        return val[0];
    }

    void add(int x){
        int i = hs++;
        val[i]=x;
        int p = (i-1)/2; //parent index;
        while(i and val[i]>val[p]){
            swap(val[i],val[p]);
            i=p;
            p=(i-1)/2;
        }
    }

    void del(int x){
        //Deleting root
        val[0]=val[--hs];
        int i=0;
        //Re-construct heap
        while(2*i+1 < hs){
            int c1 = 2 * i + 1;
            int c2 = 2 * i + 2;
            int mp=c1;

            if(c2<hs){
                if(val[c2]<val[c1]){
                    mp=c2;
                }
            }

            if (val[i]>val[mp]){
                swap(val[i],val[mp]);
                i=mp;
            }
            else break;
        }
    }

    void print(){
        for(int i=0;i<hs;i++){
            cout<<val[i]<<" ";
        }
        cout<<endl;
    }
    
    //Max heap-Sift up Min Heap - Sift Down

    void Sift_up(int ind,int x){
        val[--ind]+=x;
        int i = ind;
        int p=(i-1)/2;
        while(i and val[i]>val[p]){
            swap(val[i],val[p]);
            i=p;
            p=(i-1)/2;
        }

        cout<<++i<<endl;
    }
    void Sift_Down(int i,int x){
        val[--i]+=x;
        while(2*i+1<hs){
            int c1=2*i+1;
            int c2=2*i+2;

            if(c2<hs and val[c2]>val[c1] and val[c2]>val[i]){
                swap(val[c2],val[i]);
                i=c2;
            }

            else if(val[c1]>val[i]){
                swap(val[c1],val[i]);
                i=c1;
            }
            else break;
        }
        cout<<++i<<endl;
    }


};
int main(){
    int n,x; cin>>n;
    Heap hp;

    while(n--){
        cin>>x;
        hp.add(x);
    }

    int c,index,num; cin>>c;
    while(c--){
        cin>>index>>num;
        hp.Sift_up(index,num);
    }

    hp.print();
    
}

    d)
#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            cnt++;
            while(n%i==0){
                n=n/i;
            }
        }
        
    }
    cout<<cnt;
}

    e)
#include <iostream>
#include <vector>
using namespace std;

struct Stack{
private:
    vector<pair<int, int>> v;

public:

    void push(int x){
        if(v.empty()) v.push_back({x, x});
        else v.push_back({x, max(x, v.back().second)});
    }

    void pop(){
        if(!v.empty()) v.pop_back();
    }

    int top(){
        if(v.empty()) return 0;
        return v.back().first;
    }

    int getMax(){
        if(v.empty()) return 0;
        return v.back().second;
    }
};

int main(){

    int n, x, y; cin >> n;
    string q;
    Stack st;

    for(int i = 0; i < n; i++){
        cin >> q;
        if(q == "add"){
            cin >> x;
            st.push(x);
        }

        if(q == "delete"){
            st.pop();
        }

        if(q == "getcur"){
            y = st.top();
            (y == 0) ? cout << "error\n" : cout << y << endl;
        }

        if(q == "getmax"){
            y = st.getMax();
            (y == 0) ? cout << "error\n" : cout << y << endl;
        }
    }
}

    f)
//TRIANGLES
#include<iostream>
#include<map>
using namespace std;
map<int,int> mp;
struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
Node * add(Node * cur, int val){
    if(cur==NULL){
        return new Node(val);
    }
    else if(cur->val>val){
        cur->left=add(cur->left,val);
    }
    else if(cur->val<val){
        cur->right=add(cur->right,val);
    }
    return cur;
}
int height(Node * cur){
    if(cur==NULL) return 0;
    int l=height(cur->left);
    int r=height(cur->right);
    return max(l,r)+1;
}
int solve(Node * cur,int level){
    if(cur==NULL) return level;
    mp[cur->val]=level;
    return max(solve(cur->left,level+1),solve(cur->right,level+1));
}

int main(){
    Node * root=NULL;
    int n; cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        root=add(root,num);
    }
    solve(root,0);
    map<int,int> :: iterator it;
    int sum=0;
    for(it=mp.begin();it!=mp.end();it++){
        sum+=it->first-it->second;
    }
    cout<<sum;
    

}

    g)
#include <iostream>
using namespace std;
struct Heap{
public:
    int * a;
    int capacity, size;
    Heap(int capacity){
        a = new int[capacity];
        this->capacity = capacity;
        size = 0;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return i*2+1;
    }
    int right(int i){
        return i*2+2;
    }
    void add(int val){
        a[size] = val;
        size++;
        heapUp(size-1);
    }
    void heapUp(int i){
        int p = parent(i);
        if(a[p] > a[i]){ // if i elemnt is lower than parent than swap parent and i element
            swap(a[p], a[i]);
            heapUp(p);
        }
    }
    void heapDown(int i){
        int l = left(i);
        int r = right(i);
        int min = i;
        if(l < size && a[l] < a[min])min = l;
        if(r < size && a[r] < a[min]) min = r;
        if(min != i){
            swap(a[min], a[i]);
            heapDown(min);
        }
    }
    void extractMin(){
        swap(a[0], a[size-1]);
        size--;
        heapDown(0);
    }
    int top(){
        return a[0];
    }
    int length(){
        return size;
    }

};

int main() {
    int n; cin>>n;
    Heap h(n);
    int ans[n];
    for(int i = 0; i < n; i++){
        int ping; cin >> ping;
        h.add(ping);
        while(ping > 3000 && h.top() < ping-3000){
            h.extractMin();
        }
        ans[i] = h.length();
    }
    for(int i = 0; i < n ; i++){
        cout << ans[i] << " ";
    }

    return 0;
}

    h)
#include<iostream>
#include<vector>
using namespace std;
int cnt=0;
struct MaxHeap {
	vector<int> heap;


	int parent(int i) {return (i-1)/2;}
	int left(int i) {return (i*2)+1;}
	int right(int i) {return (i*2)+2;}

	void insert(int val) {
		heap.push_back(val);
		int i = heap.size()-1;
		while(i != 0 and heap[i]>heap[parent(i)]) {
			swap(heap[i],heap[parent(i)]);
			i = parent(i);
		}
	}

	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int biggest = i;
		if(l < heap.size() and heap[l] > heap[biggest]) biggest = l;
		if(r < heap.size() and heap[r] > heap[biggest]) biggest = r;
		if(biggest != i) {
			swap(heap[i],heap[biggest]);
			heapify(biggest);
		}
	}
    void check(int i){
        int l = this->left(i);
        int r = this->right(i);
        if(l < this->heap.size() && r<this->heap.size() && this->heap[r] > this->heap[l]){
            cnt++;
        }
    }


    
};

int main() {
    int n;cin>>n;
    MaxHeap h;
    for(int i = 0;i < n;i++) {
        int s;cin>>s;
        h.insert(s);
    }
    for(int i=0;i<h.heap.size();i++){
        h.check(i);
    }
    cout<<cnt;

}

    i)
#include <iostream>
using namespace std;
string DecimalToBinaryString(long long a){
    if(a==0) return "";
    if(a%2==0){
        return DecimalToBinaryString(a/2)+"0";
    }
    else return DecimalToBinaryString((a-1)/2)+"1";
}
string anss(string s){
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '1') cnt++;
        else if(cnt > 0) cnt--;
        else{
            return "NO";
        }
    }
    if(cnt==0) return "YES";
    else return "NO";
}
int main() {
    int n; cin >> n;
    string ans[n];
    for(int i = 0; i < n ;i++){
        long long x; cin >> x;
        ans[i] = anss(DecimalToBinaryString(x));
    }
    for(int i = 0 ; i < n ;i++){
        cout<<ans[i]<<endl;
    }

}

    j)
#include <iostream>
#include <algorithm>
using namespace std;
bool find(int arr[], int l, int r, int x){
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] == x){
            return true;
        }
        if(arr[mid] < x){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return false;
}
void swap(int * a, int * b){
    int t=*a;
    *a = *b;
    *b=t;
}
int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=(l-1);
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
void quickSort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}
int main() {
    int m, n; cin >> m >> n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i = 0; i < n ; i++){
        if(find(arr,0,n-1, m-arr[i])){
            cout << arr[i] << " " << m - arr[i];
            break;
        }
    }

    return 0;
}

    k)
#include <iostream>
#include <deque>
using namespace std;

int main(){

    int n, x, q, cnt = 0; cin >> n;
    deque<int> dq;

    for(int i = 0; i < n; i++){
        cin >> q;
        if(q == 1){
            cin >> x;
            if(cnt % 2 == 0) dq.push_back(x);
            else dq.push_front(x);
        }
        if(q == 2) cnt++;
    }

    if(cnt % 2 == 1){
        while(!dq.empty()){
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
    else{
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
}

    l)
#include<iostream>
using namespace std;
struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
Node * add(Node * cur, int val){
    if(cur==NULL){
        return new Node(val);
    }
    else if(cur->val>val){
        cur->left=add(cur->left,val);
    }
    else if(cur->val<val){
        cur->right=add(cur->right,val);
    }
    return cur;
}
int cnt = 0;
void countCh(Node * cur){
    if(cur!=NULL){
        if(cur->left==NULL and cur->right==NULL){
            cnt++;
            countCh(cur->left);
            countCh(cur->right);
        }
        else{
            if(cur->left!=NULL){
                countCh(cur->left);
            }
            if(cur->right!=NULL){
                countCh(cur->right);
            }
        }
    }
}
int main(){
    Node * root=NULL;
    int n; cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        root=add(root,num);
    }
    countCh(root);
    cout<<cnt;
    

}




*/