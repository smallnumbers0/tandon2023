//just practicing star shape patterns


#include <iostream>
using namespace std;

int main() {

    int input;

    cout <<"Please enter an integer: "<<endl;
    cin>>input;

    for(int i = 1; i <= input; i++) {
        
         for(int j = 1; j <= i; j++) { //left increasing triangle
            cout<<"*";
        }
       cout<<endl; 
    }
    return 0;
}