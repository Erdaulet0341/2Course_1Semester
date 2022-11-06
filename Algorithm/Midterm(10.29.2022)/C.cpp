#include<iostream>
using namespace std;


#define N 100001
class heap{
    public:
    int val[N];
    int hs;
    
    heap(){
        hs=0;
    }

    void insert(int x){
        int i = hs++;
        val[i]=x;
        int p = (i-1)/2;
        while(i and val[i]>val[p]){
            swap(val[i],val[p]);
            i=p;
            p=(i-1)/2;
        }
    }

    void print(){
        for(int i=0;i<hs;i++){
            cout<<val[i]<<" ";
        }
        cout<<endl;
    }

    void up(int ind,int x){
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

};
int main(){
    int n,x; cin>>n;
    heap h;

    while(n--){
        cin>>x;
        h.insert(x);
    }

    int c,index,num; 
    cin>>c;

    while(c--){
        cin>>index>>num;
        h.up(index,num);
    }

    h.print();
}