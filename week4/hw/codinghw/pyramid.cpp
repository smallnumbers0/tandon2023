//just practicing star shape patterns


#include <iostream>
using namespace std;

int main() {

    int input;

    cout <<"Please enter an integer: "<<endl;
    cin>>input;

    for(int i = 1; i <= input; i++) {
        
        for(int j = i; j <= input; j++) { //decreasing space triangle
            cout<<" ";
        }
        for(int j = 1; j <= i-1; j++) {  //increasing traingle
            cout<<"*";
        }
         for(int j = 1; j <= i; j++) { //increasing triangle
            cout<<"*";
        }

       cout<<endl; 
    }
    return 0;
}