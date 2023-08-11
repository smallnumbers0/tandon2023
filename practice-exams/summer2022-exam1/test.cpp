#include <iostream>
#include <string>
using namespace std;

int main () {
     int n, threeDigits, fourDigits, fiveDigits, sixDigits, sevenDigits;
     int evenCount, oddCount, equalCount, moreOddCount;
     bool endSeq;
     endSeq = false;

     std::cout<<"Please enter a sequence of numbers (with at least 3-digits and at most 7- digits), each one in a separate line. End your sequence by typing -1: "<<endl;
     
     threeDigits = 0;
     fourDigits = 0;
     fiveDigits = 0;
     sixDigits = 0;
     sevenDigits = 0;

     equalCount = 0;
     moreOddCount = 0;
     


     while (!endSeq) {
          cin>>n;

          if (n == -1) {
               endSeq = true;
          }

          else {
          // To check the length of each num
               int checkLength = n;
               int length = 0;

               while (checkLength > 0) {
                    checkLength /= 10;
                    length++;
               }
          
               if (length == 3 && n/100 != 0) {
                    threeDigits++;
               }          
               else if (length == 4 && n/1000 != 0) {
                    fourDigits++;
               }
               else if (length == 5 && n/10000 != 0) {
                    fiveDigits++;
               }
               else if (length == 6 && n/100000 != 0) {
                    sixDigits++;
               }
               else if (length == 7 && n/1000000 != 0) {
                    sevenDigits++;
               } 
               else {
                    cout<<"Invalid input"<<endl;
               }

          
          // To count even and odd integers
              

               evenCount = 0;
               oddCount = 0;
               int num = n;
               while (num > 0) {

                    int rem = num % 10;

                    if (rem % 2 == 0) {
                         evenCount++;
                    }
                    else {
                         oddCount++;
                    }

                    num /= 10;

                    
               }

               
               if (evenCount == oddCount) {
                    equalCount++;
               }
               else if (oddCount > evenCount){
                    moreOddCount++;
               }


          }

     }


     std::cout<<"Total count of numbers in the 3-digits Numbers Group: "<<threeDigits<<endl;

     std::cout<<"Total count of numbers in the 4-digits Numbers Group: "<<fourDigits<<endl;

     std::cout<<"Total count of numbers in the 5-digits Numbers Group: "<<fiveDigits<<endl;

     std::cout<<"Total count of numbers in the 6-digits Numbers Group: "<<sixDigits<<endl;

     std::cout<<"Total count of numbers in the 7-digits Numbers Group: "<<sevenDigits<<endl;

     std::cout<<"Total count of numbers in the More Odd-digits Group: "<<moreOddCount<<endl;

     std::cout<<"Total count of numbers in the Equal-digits Group: "<<equalCount<<endl;


     return 0;
}