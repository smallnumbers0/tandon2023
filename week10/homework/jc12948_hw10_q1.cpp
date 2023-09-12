//This program takes in a sentence and produces an array of words.
//It also updates the array size. 
//Jacky Choi NYU Tandon Summer 2023

#include <iostream>
#include <string>
using namespace std;


string* createWordsArray(string sentence, int &outWordsArrSize);

int main() {
    string sentence;
    int outWordsArrSize;
    string *outArr;
    cout<<"Please enter a sentence to be converted into an array of words: "<<endl;
    getline(cin, sentence);
    outArr = createWordsArray(sentence, outWordsArrSize);
    //making a print function for this later if i have time
    cout<<"[";
    int count = 0;
    for(int i = 0; i < outWordsArrSize; i++) {
        if(outArr[i] == "") {  //In case of continouse space "like         this"
            count++;
            continue;
        }
        else if(i == outWordsArrSize-1) {
            cout<<"\""<<outArr[i]<<"\""<<"]"<<endl;
        }
        else {
            cout<<"\""<<outArr[i]<<"\""<<", ";
        }
    }
    
    cout<<"outWordsArrSize: "<<outWordsArrSize - count<<endl;

    return 0;
}

string* createWordsArray(string sentence, int &outWordsArrSize) {
    int size = 1;
    //This loop gets the total size of array by counting spaces between words O(n)
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ') {
            size++;
        }
    }
    string *arr = new string[size];
    int count = 0;
    int j = 0;
    //this loop takes each word and store it in an index of the array O(n)
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ') {
            arr[j] = sentence.substr(count, i-count);
            cout<<arr[j]<<endl;
            count = i + 1;
            j++;
        }
    //this if statement just checks for the last word since there will be no ' ' after it. Dont want to leave this word all alone isn't that right?
        if(i == sentence.length()-1) { 
            arr[j] = sentence.substr(count, i-count + 1);
        }
    }
    outWordsArrSize = size;
    return arr;
}
