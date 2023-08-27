//This program reads a word from the user and tells the user if it is a palindrome or not.
//JAcky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
    string input;
    cout<<"Please enter a word: "<<endl;
    
    if(isPalindrome(input) == true) {
        cout<<input<<" is a palindrome."<<endl;
    }
    else cout<<input<<" is not a palindrome."<<endl;

    return 0;
}



