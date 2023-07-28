/*
Write a program that reads from the user two positive integers, and prints the result of when we add, subtract multiply, divide, div and mod them.
Your program should interact with the user exactly as it shows in the following example: Please enter two positive integers, separated by a space:
14 4
14 + 4 = 18
14 – 4 = 10 
14 * 4 = 56 
14 / 4 = 3.5 
14 div 4 = 3 
14 mod 4 = 2
*/

#include <iostream>
using namespace std;

int main() 
{

    int a, b, result;
    double divResult; //for 14/4 = 3.5

    cout<<"Please enter 2 positive integers seperated by a space: "<<endl;
    cin>>a;
    cin>>b;

    result = a + b;
    cout<<a<<" + "<<b<<" = "<<result<<endl;
    result = a - b;
    cout<<a<<" - "<<b<<" = "<<result<<endl;
    result = a * b;
    cout<<a<<" * "<<b<<" = "<<result<<endl;
    divResult = (double)a / (double)b;
    cout<<a<<" / "<<b<<" = "<<divResult<<endl;
    result = a / b;
    cout<<a<<" div "<<b<<" = "<<result<<endl;
    result = a % b;
    cout<<a<<" mod "<<b<<" = "<<result<<endl;

    return 0;
}

