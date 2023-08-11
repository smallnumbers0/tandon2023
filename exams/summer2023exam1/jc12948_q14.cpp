#include <iostream>
using namespace std;

int main() {

    int input;
    int perfectSquares = 0;
    int perfectNumbers = 0;
    int squareTemp;
    int sum;
    int perfectTemp;
   

    cout<<"Please enter a sequence of integers (with at least 1-digit and at most 9- digits), each one in a separate line. End your sequence by typing -1: "<<endl;

    cin>>input;

    while(input != -1) {
        
        if(input == 1) {
            perfectSquares++;
        }
        int temp = 0;
        sum = 0;
        perfectTemp = temp = input;
        int i = 1;
    
        while(i <= perfectTemp / 2) {
            if(perfectTemp % i == 0) {
                sum += i;
                if(i != perfectTemp / i) {
                    sum += perfectTemp / i;
                }
            }
            i++;
            if(sum == input) {
            perfectNumbers++;
        }
        }
        
           
           
    //     for (int i = 2; i * i <= num; ++i) {
    //     if (num % i == 0) {
    //         sum += i;
    //         if (i != num / i) {
    //             sum += num / i;
    //         }
    //     }
    // }
        
       


        /*******Find Perfect Squares*****/

        int j = 1;
        while(j <= input/2) {
            if(input/j == j && input%j == 0) {
                perfectSquares++;
            }
            j++;
        }
        cin>>input;
    }
      


    cout<<"Total number of perfect numbers: "<<perfectNumbers<<endl;
    cout<<"Total number of perfect squares: "<<perfectSquares<<endl;

    return 0;

}
