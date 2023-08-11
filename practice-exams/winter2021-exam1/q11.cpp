#include <iostream>
using namespace std;

int main() {

    char input;
    cout<<"Enter an lower case letter: "<<endl;
    cin>>input;

    for(int i = 0; i <= int(input - 'a'); i++) {
        for(int j = 1; j <= int(input - 'a') - i; j++) {
            cout<<' ';
        }
        for(int j = 1; j <= 2 * i + 1; j++) {
            if(i % 2 == 0) {
                cout<< char('a' + i);
            }
            else cout<< char('A' + i);
        }
        cout<<endl;
    }
   
    return 0;
}