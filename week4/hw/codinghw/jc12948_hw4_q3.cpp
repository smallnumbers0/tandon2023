/*
Question 3:
Write a program that reads from the user a positive integer (in a decimal representation), and
prints its binary (base 2) representation.
Your program should interact with the user exactly as it shows in the following example: Enter decimal number:
76
The binary representation of 76 is 1001100
Implementation Requirements:

You are not allowed to use arrays
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
 
    long int input, binaryRep = 0;
    long int remainder;
    long int position = 1; //to slowly add to ones place, tens, hundreds etc

    cout<<"Enter a decimal number: "<<endl;
    cin>>input;

    for(int temp = input; temp != 0; position *= 10) {
        remainder = temp % 2;
        temp = temp / 2;
        binaryRep += remainder * position;
    }

    cout<<input<<" is "<<binaryRep<<endl;
    return 0;
}

/**************************************/
/********WRONG STRING APPROACH*********/
/**************************************/

/*
#include <iostream>
#include <string>
int main() {

    int input, temp; 
    string binaryRep; 

    cout<<"Enter a decimal number: "<<endl;
    cin>>input;
    temp = input;

    while (temp > 0) {
        if(temp % 2 == 0) {
            binaryRep = "0" + binaryRep;
        }
        else {
            binaryRep = "1" + binaryRep;
        }
        temp /= 2;
    }

    cout<<binaryRep<<endl;
    return 0;
}
*/