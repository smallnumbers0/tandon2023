//This program determines if a string is an anagram
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
#include <string>
using namespace std;

void toLowerCase(char& letter);
bool isAnagram(string str1, string str2);

int main() {

    string inputOne;
    cout<<"Please enter a string: "<<endl;
    getline(cin, inputOne);
    string inputTwo;
    cout<<"Please enter another string to check if it is an anagram: "<<endl;
    getline(cin, inputTwo);

    for(int i = 0; i <inputOne.length(); i++) {
        toLowerCase(inputOne[i]);
    }
     for(int i = 0; i <inputTwo.length(); i++) {
        toLowerCase(inputTwo[i]);
    }

    if(isAnagram(inputOne, inputTwo)) {
        cout<<"These are anagrams"<<endl;
    }
    else cout<<"These are not anagrams"<<endl;

    return 0;
}
void toLowerCase(char& letter) {
    if (letter >= 'A' && letter <= 'Z') {
        letter += 'a' - 'A';
    }
}

bool isAnagram(string str1, string str2) {
    string alphabet[26]; //initialize an array for 26 letters of alphabet
    int lettersOne[26]; //initialize array for 26 integers
    int lettersTwo[26];
    for(int i = 0; i < 26; i++) {
        alphabet[i] = 'a' + (char)i; //store the letter of each alphabet to array
        lettersOne[i] = 0; //set the integer of each array index to 0
        lettersTwo[i] = 0;
    }

    for(int i = 0; i < str1.length(); i++) {
            lettersOne[str1[i] - 'a']++; //take letter and subtract it by 'a' ex: d - a = 3 so add 1 to lettersOne[3]. d is in position 3 in alphabet
    }
    for(int i = 0; i < str2.length(); i++) {
            lettersTwo[str2[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(lettersOne[i] != lettersTwo[i]) { //check if the number of letters are the same for each letter
            return false;
        }
    }
    return true;
}
