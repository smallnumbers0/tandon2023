#include <iostream>
using namespace std;

int main() {

    int input;

    int threeCount = 0;
    int fourCount = 0;
    int fiveCount = 0;
    int sixCount = 0;
    int sevenCount = 0;
    int oddCount;
    int evenCount;
    int oddNums = 0;
    int equalNums = 0;
    int numDigits;

        cout<<"Please enter a sequence of integers and -1 to end: "<<endl;
        cin>>input;

    while(input > 0) {
        oddCount = 0;
        evenCount = 0;
        numDigits = 0;
        //find number of digits;
        while(input > 0) {
            if(input % 2 != 0) {
                oddCount++;
            }
            else {
                evenCount++;
            }
            numDigits++;
            input /= 10;
        }
        if(numDigits == 3) {
            threeCount++;
        }
        else if(numDigits == 4) {
            fourCount++;
        }
        else if(numDigits == 5) {
            fiveCount++;
        }
        else if(numDigits == 6) {
            sixCount++;
        }
         else if(numDigits == 7) {
            sevenCount++;
        }
        else {
            numDigits = numDigits;
        }
        if(oddCount > evenCount) {
            oddNums++;
        }
        else if(oddCount == evenCount) {
            equalNums++;
        }
        else oddNums = oddNums;
        
        input = 0;
       
        cin>>input;
    }


    cout<<"3 digits: "<<threeCount<<endl;
    cout<<"4 digits: "<<fourCount<<endl;
    cout<<"5 digits: "<<fiveCount<<endl;
    cout<<"6 digits: "<<sixCount<<endl;
    cout<<"7 digits: "<<sevenCount<<endl;
    cout<<"odd nums: "<<oddNums<<endl;
    cout<<"equal nums: "<<equalNums<<endl;
    
    return 0;
}