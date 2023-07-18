/*
Write a program that asks the user to enter a number of quarters, dimes, nickels and
pennies and then outputs the monetary value of the coins in the formatof dollars andremaining cents.
Your program should interact with the user exactly as it shows in the following example: Please enter number of coins:
# of quarters: 13
# of dimes: 4
# of nickels: 11
# of pennies: 17
The total is 4 dollars and 37 cents
*/

#include <iostream>
using namespace std;

int main() {
    int quarters, dimes, nickels, pennies, dollars, cents, total;
    int const QUARTER_VALUE = 25, DIME_VALUE = 10, NICKEL_VALUE = 5, DOLLAR_VALUE = 100;

    cout<<"Please enter number of coins: "<<endl;
    cout<<"# of quarters: "<<endl;
    cin>>quarters;
    cout<<"# of dimes: "<<endl;
    cin>>dimes;
    cout<<"# of nickels: "<<endl;
    cin>>nickels;
    cout<<"# of pennies: "<<endl;
    cin>>pennies;

    total = (QUARTER_VALUE * quarters) + (DIME_VALUE * dimes) + (NICKEL_VALUE * nickels) + pennies;
    dollars = total / DOLLAR_VALUE;
    cents = total % DOLLAR_VALUE;
   

    cout<<"The total is "<<dollars<<" dollars and "<<cents<<" cents."<<endl;

}