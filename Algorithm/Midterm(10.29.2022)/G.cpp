#include <bits/stdc++.h>
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
    void insert(int val){
        a[size] = val;
        size++;
        heapUp(size-1);
    }
    void heapUp(int i){
        int p = parent(i);
        if(a[p] > a[i]){
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
    void min(){
        swap(a[0], a[size-1]);
        size--;
        heapDown(0);
    }
    int top(){
        return a[0];
    }
    int sizee(){
        return size;
    }

};

int main() {
    int n; cin>>n;
    Heap heap(n);
    int arr[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        heap.insert(x);
        while(x > 3000 && heap.top() < x-3000){
            heap.min();
        }
        arr[i] = heap.sizee();
    }
    for(int i = 0; i < n ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}