#include <iostream>
using namespace std;

int main() {

    int input;
    cout<<"enter an integer: "<<endl;
    cin>>input;

    for(int i = 1; i <= 2 * input; i++) {
        cout<<"*";
    }
    for(int i = 0; i < input; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<"*";
        }
        for(int j = i; j < input; j++) {
            cout<<" ";
        }
        for(int j = i; j < input; j++) {
            cout<<" ";
        }
         for(int j = 1; j <= i; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
     for(int i = 0; i < input; i++) {
        for(int j = i; j <= input - 1; j++) {
            cout<<"*";
        }
        for(int j = 1; j <= i; j++) {
            cout<<" ";
        }
        for(int j = 1; j <= i; j++) {
            cout<<" ";
        }
        for(int j = i; j <= input - 1; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
     for(int i = 1; i <= 2 * input; i++) {
        cout<<"*";
    }
    return 0;
}