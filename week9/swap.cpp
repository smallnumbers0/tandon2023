#include <iostream>
using namespace std;

void swap(int &a, int &b); //pass by reference

int main() {
    int a = 10;
    int b = 5;
    cout<<"Before swap a:b "<<a<<":"<<b<<endl;

    swap(a, b);

    cout<<"After swap a:b "<<a<<":"<<b<<endl;
    return 0;
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}