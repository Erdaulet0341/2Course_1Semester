#include<bits/stdc++.h>
using namespace std;

int cnt=0;

class heap{
    public:
	vector<int> v;

	int parent(int i) {
        return (i-1)/2;
    }
	int left(int i) {
        return (i*2)+1;
    }
	int right(int i) {
        return (i*2)+2;
    }

	void insert(int val) {
		v.push_back(val);
		int i = v.size()-1;
		while(i != 0 and v[i]>v[parent(i)]) {
			swap(v[i],v[parent(i)]);
			i = parent(i);
		}
	}

	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int large = i;
		if(l < v.size() and v[l] > v[large]) large = l;
		if(r < v.size() and v[r] > v[large]) large = r;
		if(large != i) {
			swap(v[i],v[large]);
			heapify(large);
		}
	}

    void check(int i){
        int l = this->left(i);
        int r = this->right(i);
        if(l < this->v.size() && r<this->v.size() && this->v[r] > this->v[l]){
            cnt++;
        }
    }   
};

int main() {
    int n;
    cin>>n;
    heap h;

    for(int i = 0;i < n;i++) {
        int s;cin>>s;
        h.insert(s);
    }

    for(int i=0;i<h.v.size();i++){
        h.check(i);
    }
    cout << cnt;

}