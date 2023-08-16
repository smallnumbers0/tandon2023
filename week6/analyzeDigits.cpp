#include <iostream>
using namespace std;

int analyzeDigits(int num, int &outSum);

int main() {
    int num, countDigits, sumDigits;
    cout<<"Please enter a positive integer: "<<endl;
    cin>>num;

    countDigits = analyzeDigits(num, sumDigits);

    cout<<num<<" has "<<countDigits<<" digits and their sum is "<<sumDigits<<endl;
    return 0;
}

int analyzeDigits(int num, int &outSum) {
    int count, sum;
    int currDigit;

    count = 0;
    sum = 0;
    while(num > 0) {
        currDigit = num % 10;
        count++;
        sum += currDigit;
        num /= 10;
    }
    outSum = sum;
    return count;
}