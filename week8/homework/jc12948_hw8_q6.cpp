//This program takes in a string of text and replaces all integers that are by themselves into "x"s. 
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
#include <string>
using namespace std;

string convertToX(string word);
bool isDigit(string word);

int main() {
    string input;
    cout<<"Please enter a line of text: "<<endl;
    getline(cin, input);

    int count = 0;
    string temp = "test";
    for(int i = 0; i <= input.length(); i++) {
        if(input[i] == ' ' || i == input.length()) {
            temp = input.substr(count, i - count);
            cout<<convertToX(temp)<<" ";
            count = i + 1;
        }
    }
    cout<<endl;

    return 0;
}

bool isDigit(string word) {
    for(int i = 0; i < word.length(); i++) {
       if (word[i] < '0' || word[i] > '9') {
            return false;
        }
    }
    return true;
}

string convertToX(string word) {
    
    if(isDigit(word) == true) {
        string convertWord;
        for(int i = 0; i < word.length(); i++) {
            convertWord += 'x';
        }
        return convertWord;
    }
    else {
        return word;
    }
}

//seperate whole string sentence by " "
//find the words that only have integers in them
//change all the words that only have integers into "x"s
//print out new string