/*
Write a program that:
• Asks the user for their name.
• Asks the user to input their graduation year.
• Asks the user to input the current year.
Assume the student is in a four-year undergraduate program. Display the current status the student is in. Possible status include: not in college yet, freshman, sophomore, junior, senior, graduated.
Note: If graduation year equals to current year, status is ‘Graduated’; if graduation year is four years after current year, status is ‘Freshman’, etc.
Your program should interact with the user exactly as it shows in the following example: Please enter your name: Jessica
Please enter your graduation year: 2019
Please enter current year: 2015
Jessica, you are a Freshman
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

    string name;
    int graduationYear, currentYear;

    cout<<"Please enter your name: "<<endl;
    cin>>name;
    cout<<"Please enter your graduation year: "<<endl;
    cin>>graduationYear;
    cout<<"Please enter current year: "<<endl;
    cin>>currentYear;

    if(currentYear >= graduationYear) {
        cout<<name<<", you have graduated."<<endl;
    }
    else if(graduationYear - currentYear == 1) {
        cout<<name<<", you are a senior."<<endl;
    }
    else if(graduationYear - currentYear == 2) {
        cout<<name<<", you are a junior."<<endl;
    }
    else if(graduationYear - currentYear == 3) {
        cout<<name<<", you are a sophmore"<<endl;
    }
    else if(graduationYear - currentYear == 4) {
        cout<<name<<", you are a freshmen"<<endl;
    }
    else    
        cout<<name<<", you are not in college yet"<<endl;


return 0;
}