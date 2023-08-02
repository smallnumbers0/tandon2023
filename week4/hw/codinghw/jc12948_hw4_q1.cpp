/*
Question 1:
Write two versions of a program that reads a positive integer n, and prints the first n even numbers.
a) In the first, use a while loop.
b) In the second, use a for loop.
Each section should interact with the user exactly as it shows in the following example: Please enter a positive integer: 3
2
4
6
*/

// #include <iostream>

// using namespace std;

// int main() {
    
//     int input;

//     cout<<"Please enter a positive integer: "<<endl;
//     cin>>input;

//     for(int i = 1; i <= input; i++) {
//         cout<<i<<": "<<i * 2<<endl;
//     }
//     return 0;
// }

#include <iostream>

using namespace std;

int main() {
    int input;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>input;

    int i = 1;
    while(i <= input) {
        cout<<i<<": "<<i * 2<<endl;
        i++;
    }
    return 0;
}