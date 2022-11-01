#include <iostream>
using namespace std;

int main(){
    int a = 5;
    cout << &a << endl;  //adress of a n variable
    int* ptr = &a;
    cout << ptr << endl; //print adrees of n
    cout << *ptr << endl; // print value of n;
    *ptr = 10;   // change value of n
    cout << *ptr << endl; //10
    cout << a << endl; //10
    return 0;
}