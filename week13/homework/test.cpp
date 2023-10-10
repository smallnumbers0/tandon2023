#include <iostream>
using namespace std;

int main() {

    for(int i = 0; i <= 400; i++) {
        if(i % 20 == 0 && i != 400 && i != 0) {
            cout<<i<<endl;
        }
        else
            cout<<i<<" ";
    }
    cout<<endl;
}