//This program takes an array and returns the numbers missing from the array from 0 to n.
//Jacky Choi NYU Tandon Summer 2023

#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
const int ARR_SIZE = 6;
int main() {
    int newSize = 0;
    int numArr[ARR_SIZE] = {0, 1, 2, 2, 4, 9};

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
    newArr = NULL;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int orderedCount[n + 1];
    for(int i = 0; i <= n; i++) {
        orderedCount[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        orderedCount[arr[i]]++;
    }
    for(int i = 0; i <= n; i++) {
        if(orderedCount[i] == 0) {
            resArrSize++;
        }
    }
    int *missingNums = new int[resArrSize];
    int count = 0;
    for(int i = 0; i <= n; i++) {
        if(orderedCount[i] == 0) {
            missingNums[count] = i;
            count++;
        }
    }
    return missingNums;
}