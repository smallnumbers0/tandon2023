//Jacky Choi
//jc12948

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(string str);

int main() {
    int count = 0;
    vector <string> nums;
    vector <string> valid;
    string input;
    cout<<"Please enter a non-empty sequence of Strings consisting of only decimal digits. To indicate the end of the input, enter an empty string in one line: "<<endl;

    while(true) {
        getline(cin, input);
        if(input == "") { 
            break;
        }
        nums.push_back(input);
    }

    for(int i = 0; i < nums.size(); i++) {
        if(isValid(nums[i])) {
            valid.push_back(nums[i]);
        }
        else {
            count++;
        }
    }
    cout<<"These are the strings that only contain '0' or '1': "<<endl;
    for(int i = 0; i < valid.size(); i++) {
        cout<<valid[i]<<" ";
    }
    cout<<endl;

    cout<<"This is the number of deleted strings containing at least one character that is not a '0' or '1': "<<endl;
    cout<<count<<endl;
    return 0;
}

    bool isValid(string str) {
        for(int i = 0; i < str.length(); i++) {
            if(str[i] != '0' && str[i] != '1') {
                return false;
            }
        }
        return true;
    }