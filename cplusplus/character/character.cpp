#include <iostream>
using namespace std;

int main() {
    char input;

    cout<<"Please enter a character: "<<endl;
    cin>>input;
    if(input >= 'a' && input <= 'z') {
        cout<<input<<" is a lowercase letter"<<endl;
    }
    else if(input >= 'A' && input <= 'Z') {
        cout<<input<<" is a uppercase letter"<<endl;
    }
    else if(input >= '0' && input <= '9') {
        cout<<input<<" is a digit"<<endl;
    }
    else {
        cout<<input<<" is not an alpha-numeric character"<<endl;
    }
    return 0;
}