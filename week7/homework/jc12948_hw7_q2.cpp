/*
Question 2: Divisors and Perfect Number Functions w/ O(sqrt(n))
Jacky Choi 08/20/2023
jc12948 hw 7 q2
*/

#include <iostream>
using namespace std;

void analyzeDivisors (int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() { 
    int input;
    cout<<"Please enter a positive integer greater than or equal to 2: "<<endl;
    cin>>input;

    cout<<input<<endl;
    return 0;
}