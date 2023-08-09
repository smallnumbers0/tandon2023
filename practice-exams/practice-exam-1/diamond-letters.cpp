#include <iostream>
using namespace std;

int main() {

    int input;
    char letter = 'a';

    cout<<"Enter an integer"<<endl;
    cin>>input;

    for(int i = 0; i < input; i++) {
        for(int j = i; j < input; j++) {
            cout<<" ";
        }
        cout<<char(letter + i);
        for(int j = 0; j < i-1; j++) {
                cout<<" ";
        }
         for(int j = -1; j < i ; j++) {
            cout<<" ";
        }
        if(char(letter+i) == 'a') {
            cout<<"";
        }
        else{
            cout<<char(letter + i);
        }
        cout<<endl;
    }
    int count = input;
    for(int i = 1; i < input; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<" ";
        }
        cout<<" ";
        cout<<char(letter + count - 2);
        for(int j = i; j < input -1; j++) {
            cout<<" ";
        }
        for(int j = i; j < input-1; j++) {
            cout<<" ";
        }
        if(char(letter+ count - 2) == 'a') {
            cout<<"";
        }
        else{
        cout<<char(letter + count - 2);
        }
        cout<<endl;
        count--;
       
    }


    return 0;

}