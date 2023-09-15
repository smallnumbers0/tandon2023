//Jacky Choi NYU Tandon Summer 2023
// Question 2:
// Implement the function:
// int* findMissing(int arr[], int n, int& resArrSize)
// This function gets an array of integers arr and its logical size n. All elements in arr are in the range {0, 1, 2, ... , n}.
// Note that since the array contains n numbers taken from a range of size n+1, there must be at least one number that is missing (could be more than one number missing, if there are duplicate values in arr).
// When called, it should create and return a new array, that contains all the numbers in range {0, 1, 2, ... , n} that are not in arr. The function should also update the output parameter, resArrSize, with the logical size of the new array that was created.
// For example, if arr=[3, 1, 3, 0, 6, 4], after calling
// findMissing(arr, 6, resArrSize), the function should create and return an array that contains [2, 5], and update the value in resArrSize to be 2.
// Implementation requirements:
// 1. Your function should run in linear time. That is, it should run in 𝜃(𝑛).
// 2. Write a main() program that tests this function..

#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
const int ARR_SIZE = 6;
int main() {
    int newSize = 0;
    int numArr[ARR_SIZE] = {1, 5, 4, 5, 4, 3};

    cout<<"Before: "<<endl;    
    cout<<"[";
    for(int i = 0; i < ARR_SIZE; i++) {
        if(i == ARR_SIZE - 1) {
            cout<<numArr[i]<<"]"<<endl;
        }
        else {
            cout<<numArr[i]<<", ";
        }
    }

    int* newArr = findMissing(numArr, ARR_SIZE, newSize);
    for(int i = 0; i < newSize; i++) {
        cout<<newArr[i]<<endl;
    }
    delete[] newArr;
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int* orderedCount = new int[n];
    for(int i = 1; i <= n; i++) {
        orderedCount[i] = i;
    }

    for(int i = 1; i <= n; i++) {
        if(arr[i] != i) {
            resArrSize++;
        }
    }
    int *missingNums = new int[resArrSize];
    int count = 0;
     for(int i = 1; i <= resArrSize; i++) {
        if(arr[i] != i) {
            missingNums[count] = arr[i];
            count++;
        }
    }
    
    return missingNums;
}