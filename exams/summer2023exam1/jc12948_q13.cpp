#include <iostream>
using namespace std;

int main() {

    int input;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>input;

    for(int i = 0; i <= input; i++) {
        for(int j = i; j < input; j++) {
            cout<<" ";
        }
        for(int j = i; j <= 2 * i; j++) {
            cout<<"*";
        }
        for(int j = i; j < 2 * i; j++) {
            cout<<"*";
        }
         cout<<endl;
    }
    for(int i = 0; i < input; i++) {
        for(int j = 0; j <= i; j++) {
            cout<<" ";
        }
        for(int j = i; j < input; j++) {
            cout<<"*";
        }
         for(int j = i; j < input-1; j++) {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}