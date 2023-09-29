//Jacky Choi
//jc12948

#include <iostream>
using namespace std;

int findOddIntegersAndSum(int S[], int length, int& sumOdds);

int main() {
    int arr[8] = {10, -5, -20, 0, 7, -15, -5, -101}; 
    int size = 8;

    int sumOdds = 0;
    cout<<"Count of odds: "<<findOddIntegersAndSum(arr, size, sumOdds)<<endl;
    cout<<"Sum of Odds: "<<sumOdds<<endl;
    return 0;
}


int findOddIntegersAndSum(int S[], int length, int& sumOdds) {
    int count = 0;
    if(length == 0) {
        return 0;
    }
    else {
        if(S[0] % 2 == 1 || S[0] % 2 == -1) {
            sumOdds += S[0];
            count++;
        }
        return count + findOddIntegersAndSum(S+1, length-1, sumOdds);
    }
}
