/*
Question 2: Divisors and Perfect Number Functions w/ O(sqrt(n))
Jacky Choi 08/20/2023
jc12948 hw 7 q2
*/

#include <iostream>
#include <cmath>
using namespace std;


void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
void printPerfNums(int num);
void printAmicableNums(int num);

int main() { 
    int input;
    int outCountDivs = 1;
    int outSumDivs = 1;
    cout<<"Please enter a positive integer greater than or equal to 2: "<<endl;
    cin>>input;
    analyzeDivisors(input, outCountDivs, outSumDivs);
    cout<<outCountDivs<<endl;
    cout<<outSumDivs<<endl;

    if(isPerfect(input) == true) {
        cout<<"This number is a perfect number."<<endl;
    }
    else cout<<"This number is not a perfect number."<<endl;
    printPerfNums(input);
    printAmicableNums(input);
    return 0;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {

    for (int i = 2; i <= sqrt(num); i++) { //sqrt(num) to satisfy effieicnet implementation requirement
        if (num % i == 0) {
            outCountDivs++;

            if (num != int(num / sqrt(num))) { 
                outCountDivs++;
                outSumDivs += i + num / i;
            } else {
                outSumDivs += i;
            }
        }
    }
}

bool isPerfect(int num) {
    int countDivs = 1;
    int sumDivs = 1;
    analyzeDivisors(num, countDivs, sumDivs);
    // cout<<num<<endl;
    // cout<<countDivs<<endl;
    // cout<<sumDivs<<endl;
    if(num == sumDivs) {
        return true;
    }
    else return false;
}

void printAmicableNums(int num) {
    cout<<"Amicable Numbers from 2 to "<<num<<": "<<endl;
    for(int i = 2; i <= num; i++) {
        int countDivs = 1;
        int sumDivs = 1;
        int sumDivsPair = 1;
        
        analyzeDivisors(i, countDivs, sumDivs);
        int temp = sumDivs;
        analyzeDivisors(temp, countDivs, sumDivsPair);
        if(i == sumDivsPair && i < temp) {
            cout<<"("<<i<<", "<<sumDivs<<")"<<endl;
        }
    }

}

void printPerfNums(int num) {
    cout<<"Perfect numbers from 2 to "<<num<<": "<<endl;
    for(int i = 2; i <= num; i++) {
        if(isPerfect(i) == true) {
            cout<<i<<" "<<endl;
        }
    }
}
