//just practicing star shape patterns


#include <iostream>
using namespace std;

int main() {

    int input;

    cout <<"Please enter an integer: "<<endl;
    cin>>input;



     for(int i = 1; i <= input -1; i++) {
        
         for(int j = i; j <= input; j++) {
            cout<<"  ";
        }
        for(int j = 1; j <= i-1; j++) {
            cout<<"* ";
        }
         for(int j = 1; j <= i; j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
  
   for(int i = 1; i <= input; i++) {
        
         for(int j = 1; j <= i; j++) { //increasing space
            cout<<"  ";
        }
        for(int j = i; j <= input -1; j++) {
            cout<<"* ";
        }
         for(int j = i; j <= input; j++) { /********decreasing star************/
            cout<<"* ";
        }
       
       
        cout<<endl;
    }
    return 0;
}