/*
Question 2:
Write a program that asks the user to enter an amount of money in the format of dollars andremaining cents. The program should calculate and print the minimum number of coins (quarters, dimes, nickels and pennies) that are equivalent to the given amount.
Hint: In order to 5ind the minimum number of coins, 5irst 5ind the maximum number of quarters that 5it in the given amount of money, then 5ind the maximum number of dimes that 5it in the remaining amount, and so on.
Your program should interact with the user exactly as it shows in the following example: Please enter your amount in the format of dollars and cents separated by a space:
4 37
4 dollars and 37 cents are:
17 quarters, 1 dimes, 0 nickels and 2 pennies
*/

#include <iostream>
using namespace std;

int main() 
{
    int quarters, dimes, nickels, pennies, dollars, cents, total;
    int const QUARTER_VALUE = 25, DIME_VALUE = 10, NICKEL_VALUE = 5, DOLLAR_VALUE = 100;

    cout<<"Please enter your amount in the format of dollars and cents separated by a space: "<<endl;

    cin>>dollars>>cents;
   

    total = dollars * DOLLAR_VALUE + cents;
    quarters = total / QUARTER_VALUE;
    dimes = (total - (quarters * QUARTER_VALUE)) / DIME_VALUE;
    nickels = (total - ((quarters * QUARTER_VALUE) + (dimes * DIME_VALUE))) / NICKEL_VALUE;
    pennies = total - ((quarters * QUARTER_VALUE) + (dimes * DIME_VALUE) + (nickels * NICKEL_VALUE));

    cout<<dollars<<" dollars and "<<cents<<" cents are: "<<endl;
    cout<<quarters<<" quarter(s), "<<dimes<<" dime(s), "<<nickels<<" nickel(s), "<<pennies<<" pennie(s)"<<endl;
   

}