/*Question 6:
Write a program that asks the user to input a positive integer n, and print all of the numbers from 1 to n that have more even digits than odd digits.
For example, if n=30, the program should print:
2
4
6
8
20
22
24
26
28
*/
#include <iostream>
using namespace std;

int main() {


    int input, counterEven = 0, counterOdd = 0;
    cout<<"Please enter an integer: "<<endl;
    cin>>input;

    for(int i = 0; i <= input; i++) {
        int countOdd = 0;
        int countEven = 0;
        
        for(int temp = i; temp > 0; temp /= 10) {
            int tempDigit = temp % 10; //check each digit seperately
            if(tempDigit % 2 != 0) {
                countOdd++;
            }
            else {
                countEven++;
            }
        }
        
        if(countOdd < countEven) {
            cout<< i <<endl;
        }
    }

    return 0;
}