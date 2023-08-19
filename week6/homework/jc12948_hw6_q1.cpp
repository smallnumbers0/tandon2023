/*
The Fibonacci numbers sequence, Fn, is defined as follows:
F1 is1,F2 is1,andFn =Fn-1 +Fn-2forn=3,4,5,...
In other words, each number is the sum of the previous two numbers. The first 10 numbers in Fibonacci sequence are: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
Note: Background of Fibonacci sequence: https://en.wikipedia.org/wiki/Fibonacci_number
1. Write a function int fib(int n) that returns the n-th element of the Fibonacci
sequence.
2. Write a program that prompts the user to enter a positive integer num, and then
prints the num’s elements in the Fibonacci sequence.Your program should interact with the user exactly as it shows in the following example:
Please enter a positive integer: 7
13
*/

#include <iostream>
using namespace std;

int fib(int n);

int main() {
    int input, result;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>input;
    result = fib(input);
    cout<<result<<endl;
    return 0;
}

int fib(int n) {
    int previous_one = 1; 
    int previous_two = 0; 
    int result = 0;
    for(int i = 1; i <= n; i++) {
        previous_two = previous_one;
        previous_one = result;
        result = previous_one + previous_two;
    }
    return result;
}