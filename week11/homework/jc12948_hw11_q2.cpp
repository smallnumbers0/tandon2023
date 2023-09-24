// Give a recursive implement to the following functions:
// a. int sumOfSquares(int arr[], int arrSize)
// This function is given arr, an array of integers, and its logical size, arrSize. When called,
// it returns the sum of the squares of each of the values in arr.
// For example, if arr is an array containing [2, -1, 3, 10], calling sumOfSquares(arr, 4)
// will return 114 (since, 22 + (-1)2 + 32 + 102 = 114).
// b. bool isSorted(int arr[], int arrSize)
// This function is given arr, an array of integers, and its logical size, arrSize. When called,
// it should return true if the elements in arr are sorted in an ascending order, or false if
// they are not

//This program retuns the sum of the square of elements in an array using recursion.
//It also returns a boolean value to tell if the array is sorted or not using recursion.
// Jacky Choi NYU Tandon Bridge Summer2023

#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    const int size = 4;
    int arr[size] = {0, 2, 2, 4};
    cout<<sumOfSquares(arr, size)<<endl;
    if(isSorted(arr, size)) {
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }
    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    // if(arrSize == 1) { //is there a better base case?
    //     return arr[0] * arr[0];
    // }
    if(arrSize == 0) {
        return 0;
    }
    else {
        int temp = arr[arrSize-1] * arr[arrSize-1];
        return temp + sumOfSquares(arr, arrSize-1);
    }
}

bool isSorted(int arr[], int arrSize) {
    if(arrSize == 1) { 
        return true;
    }
    else {
        int previous = arr[arrSize - 2];
        int present = arr[arrSize - 1];
       
        return (previous <= present) && isSorted(arr, arrSize -1);
    }
}