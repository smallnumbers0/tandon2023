//This program takes in a string of text and replaces all integers that are by themselves into "x"s. 
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
#include <string>
using namespace std;

char convertIntegers(char temp);

int main() {

    string input = "test"; 
    string result = "well";
    cout<<"Enter a string of text: "<<endl;
    getline(cin, input);

    for(int i = 0; i < input.length(); i++) {
        int count = 0;
        string temp = "";
        if(input[i] == ' ') {
            temp = input.substr(count, i);
            cout<<temp<<endl;
            count = i;
        }
        for(int i = 0; i < temp.length(); i++) {
                if(temp[i] != '1' || temp[i] != '2' || temp[i] != '3' || temp[i] != '4' || temp[i] != '5' || temp[i] != '6' || temp[i] != '7' || temp[i] != '8' || temp[i] != '9' || temp[i] != '0') {
                    temp[i] = temp[i];
                }
                else {
                    temp[i] = convertIntegers(temp[i]) + ' ';
                }
        }
        count++;
        result += temp;
    }
    cout<<result<<endl;
    return 0;
}
char convertIntegers(char temp) {
    return temp = 'x';
    
}
//seperate whole string sentence by " "
//find the words that only have integers in them
//change all the words that only have integers into "x"s
//print out new string