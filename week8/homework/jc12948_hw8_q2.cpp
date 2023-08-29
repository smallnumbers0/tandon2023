//This program reads a word from the user and tells the user if it is a palindrome or not.
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
    string input;
    cout<<"Please enter a word: "<<endl;
    cin>>input;
    
    if(isPalindrome(input)) {
        cout<<input<<" is a palindrome."<<endl;
    }
    else cout<<input<<" is not a palindrome."<<endl;

    return 0;
}

bool isPalindrome(string str) {
    string temp;
    int j = 0;
    for(int i = str.length(); i >= 0; i--) {
        if(str[i-1] != str[j]) {
            return false;
            break;
        }
        j++;
        if(j == str.length()-1) {
            break;
        }
    }
    return true;
}
    


