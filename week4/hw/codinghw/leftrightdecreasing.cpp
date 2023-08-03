//just practicing star shape patterns


#include <iostream>
using namespace std;

int main() {

    int input;

    cout <<"Please enter an integer: "<<endl;
    cin>>input;

    for(int i = 1; i <= input; i++) {
        
         for(int j = i; j <= input; j++) { //left decreasing triangle
            cout<<"*";
        }
       cout<<endl; 
    }
    return 0;
}