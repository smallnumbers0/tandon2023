#include <iostream>
using namespace std;

bool hasDigits(string &str);

int main() {
    vector <string> seq;
    string input;
    int count;
    cout<<"Please enter a sequence of strings: "<<endl;
    while(true) {
        getline(cin,input);
        if(input.empty()) {
            break;
        }
        seq.push_back(input);
    }

    vector <string> validStrings;
    for(int i = 0; i < seq.size(); i++) {
        string str = seq[i];
        if(hasDigits(str)) {
            validStrings.push_back(str);
        }
        else {
            count++;
        }
    }

    cout<<"lower case only: "<<count<<endl;
    for(int i = 0; i < validStrings.size(); i++) {
        cout<<validStrings[i]<<endl;
    }
    return 0;
}




bool hasDigits(string &str) {
    for(int i = 0; i < str.length(); i++) {
        char c = str[i];
        if(c >= '0' && c <= '9') {
            return true;
        }
    }
    return false;
}