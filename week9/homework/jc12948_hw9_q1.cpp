//This program counts the number of words in a line of text and also the number of each letter.
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
using namespace std;

int countWords(string str);
void countLetters(string str);
void toLowerCase (char& letter);

const char PERIOD = '.';
const char COMMA = ',';
const char SPACE = ' ';

int main() {
    string input;
    cout<<"Please enter a line of text: "<<endl;
    getline(cin, input);

    for(int i = 0; i < input.length(); i++) {
        toLowerCase(input[i]);
    }

    cout<<input<<endl;
    cout<<countWords(input)<<"\twords"<<endl;
    countLetters(input);
    return 0;
}

//lowercase all letters of line
void toLowerCase(char& letter) {
    if (letter >= 'A' && letter <= 'Z') {
        letter += 'a' - 'A';
    }
}

//count number of words based on puncuation
int countWords(string str) {
    int numWords = 0;
    bool isWord;
    isWord = true; 
    for(int i = 0; i < str.length(); i++) { 
        if(isWord == true && (str[i] == PERIOD || str[i] == COMMA || str[i] == SPACE)) {
            isWord = false;
        }
        else if(isWord == false && (str[i] >= 'a' && str[i] <= 'z')) {
            numWords++;
            isWord = true;
        }  
    }
    return numWords + 1;
}

//count number of letters using ASCII
void countLetters(string str) {
    string alphabet[26];
    int letterCount[26];
    for(int i = 0; i < 26; i++) {
        alphabet[i] = 'a' + (char)i;
        letterCount[i] = 0;
    }
    for(int i = 0; i < str.length(); i++) {
        if(str[i] != PERIOD && str[i] != COMMA && str[i] != SPACE) {
            letterCount[str[i] - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++) {
        if(letterCount[i] > 0) {
            cout<<letterCount[i]<< "\t"<<alphabet[i]<<endl;
        }
    }
    
}