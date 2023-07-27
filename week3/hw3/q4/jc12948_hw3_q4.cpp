/*
Define the following constants:
Write a program that asks the user to enter a Real number, then it asks the user to enter the method by which they want to round that number (floor, ceiling or to the nearest integer). The program will then print the rounded result.
Your program should interact with the user exactly as it shows in the following example: Please enter a Real number:
4.78
Choose your rounding method:
1. Floor round
2. Ceiling round
3. Round to the nearest whole number 2
5
Implementation requirements:
1. Use a switch statement.
2. You are not allowed to include and use the math library.
*/

#include <iostream>
using namespace std;

int main() {
    double userInput, decimal;
    int roundMethod, roundedInput;
    int temp; //turn userInput into int to remove decimal

    cout<<"Please enter a Real Number: "<<endl;
    cin>>userInput;
    cout<<"Choose your rounding method: "<<endl;
    cout<<"1. Floor round\n2. Ceiling round\n3. Round to Nearest Integer"<<endl;
    cin>>roundMethod;

    switch(roundMethod) {
        case 1: 
            //temp = userinput
            //if userinput  >= 0 { decimal = userinput - temp } else  decimal = temp - userinput
            //roundednumber = temp
            temp = userInput;
            if(userInput >= 0) {
                decimal = userInput - temp;
            }
            else {
                decimal = temp - userInput;
            }
            
            if(temp < 0 && decimal > 0) {
                roundedInput = temp - 1;
            }
            else {
                roundedInput = temp;
            }
            cout<<roundedInput<<endl;
            break;
        
        case 2:
            temp = userInput;
            if(userInput >= 0) {
                decimal = userInput - temp;
            }
            else {
                decimal = temp - userInput;
            }
            
            if(temp >= 0 && decimal > 0) {
                roundedInput = temp + 1;
            }
            else {
                roundedInput = temp;
            }
            cout<<roundedInput<<endl;
            break;
            

        case 3:
            temp = userInput;
            if(userInput >= 0) {
                decimal = userInput - temp;
            }
            else {
                decimal = temp - userInput;
            }

            if(decimal >= 0.5 && temp >= 0) {
                roundedInput = temp + 1;
            }
            else if(decimal >= 0.5 && temp < 0)  {
                roundedInput = temp - 1;
            }
            else roundedInput = temp;
            cout<<roundedInput<<endl;
            break;
            
    }


}