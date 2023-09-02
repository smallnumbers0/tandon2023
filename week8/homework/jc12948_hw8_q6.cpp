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
    string result = "";
    int count = 0;
    string temp = "test";
    for(int i = 0; i <= input.length(); i++) {
        if(input[i] == ' ' || i == input.length()) {
            temp = input.substr(count, i - count);
            //cout<<temp<<endl;
            result = result + convertToX(temp) + ' ';
            count = i + 1;
        }
    }
    cout<<result<<endl;

    return 0;
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

bool isDigit(string word) {
    for(int i = 0; i < word.length(); i++) {
        if(word[i] != '1' && word[i] != '2' && word[i] != '3' && word[i] != '4' && word[i] != '5' && word[i] != '6' && word[i] != '7' && word[i] != '8' && word[i] != '9' && word[i] != '0') {
            return false;
        }
    }
    return true;
}
//seperate whole string sentence by " "
//find the words that only have integers in them
//change all the words that only have integers into "x"s
//print out new string