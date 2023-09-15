//Jacky Choi NYU Tandon Summer 2023
// Question 3:
// In this question, you will write two versions of a program that reads from the user a sequence of positive integers ending with -1, and another positive integer num that the user wishes to search for.
// The program should then print all the line numbers in sequence entered by the user, that contain num, or a message saying that num does not show at all in the sequence. 13 5 8 2 9 5 8 8 -1
// Please enter a number you want to search. 5
// 5 shows in lines 2, 6.
// a) The first version of the program, is not allowed to use the vector data structure.
// b) The second version of the program, should use the vector data structure.
// Implementation requirements (for both programs):
// 1. Think how to break down your implementation to functions.
// 2. Your programs should run in linear time. That is, if there are n numbers in the input
// sequence, your program should run in 𝜃(𝑛).
// 3. Write the two programs in two functions named main1() and main2(). Also have
// the main() test these two functions.

#include <iostream>
#include <vector>
using namespace std;

void main1();

int main() {
    main1();
    return 0;
}

void main1() { //This function does not use vector
    int size = 0;
    int* arr = new int[size];
    //use a ptr to create dynamic memory heap
    //we increment size for every input
    //an input of -1 stops sequence
    int input = 0;
    while(input != -1) {
        cin>>input;
        if(input == -1) { 
            break; //break here so -1 is not in array.
        }
        arr[size] = input;
        size++;
    }

    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<endl;
    }

}