/* 
Write two versions of a program that reads a sequence of positive integers from the user,
calculates their geometric mean, and print the geometric mean. 
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int product = 1;
    int input;
    double seqLength, geometricMean;

    cout<<"Please enter the length of the sequence: "<<endl;
    cin>>seqLength;

    //get number of inputs according to sequence length
    cout<<"Please enter your sequence of positive integers: "<<endl;

    for(int i = 0; i < seqLength; i++) {
        cin>>input;
        product *= input;
    }

    geometricMean = pow(product, (1/seqLength));
    cout<<geometricMean<<endl;

    return 0;
}
/*************************************************************************************************************************************/
/******************************/
/********Terminate with -1****/
/******************************/

// #include <iostream>
// #include <cmath>

// using namespace std;

// int main() {
    
//     int product = 1; 
//     int input;
//     double seqLength, geometricMean;

//         cout<<"Please enter a non-empty sequence of positive integers, each one in a seperate line. End your sequence by typing -1: "<<endl;
//         cin>>input;
//         while(input != -1) {
//             product *= input;
//             seqLength++;
//             cin>>input;
//         }

//         geometricMean = pow(product, (1/seqLength));
//         cout<<geometricMean<<endl;

//         return 0;
// }