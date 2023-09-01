#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "abcdbcdefg";

    cout<<str.find("de")<<endl;
    if(str.find("xyz") == string::npos) {
        cout<<"Not found"<<endl;
    }
    else cout<<"Found"<<endl;

    cout<<str.find("cd")<<endl;

    return 0;
}