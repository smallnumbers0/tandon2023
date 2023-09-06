//This program counts the number of words in a line of text and also the number of each letter.
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
using namespace std;

int countWords(string str);
int countLetters(string str);

int main() {

    string input;
    cout<<"Please enter a line of text: "<<endl;
    cin>>input;

    cout<<input<<endl;
    return 0;
}
//This function splits the words by the delimiters (period space, or comma) and returns the number of words.
int countWords(string str) {
    int numWords = 0;
    int count = 0;
    for(int i = 0; i < str.length(); i++) {
        //seperate words by delimiters " ,."
    }
}