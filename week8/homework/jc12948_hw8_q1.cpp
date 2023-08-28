//This program takes in an array of 20 numbers and returns the lowest number.
//NYU Tandon Bridge Summer 2023

#include <iostream>
using namespace std;

const int AMOUNT_OF_NUMS = 20;

int minInArray(int arr[], int arrSize);

int main() {
    int arr[AMOUNT_OF_NUMS];
    int lowestNum;
    cout<<"Please enter up to 20 integers: "<<endl;
    for(int i = 0; i < AMOUNT_OF_NUMS; i++) {
        cin>>arr[i];
    }
    lowestNum = minInArray(arr, AMOUNT_OF_NUMS);

    cout<<"The lowest number in the array is: "<<lowestNum<<" and is located in the following indices: "<<endl;
    for(int i = 0; i < AMOUNT_OF_NUMS; i++) {
        if(lowestNum == arr[i]) {
            cout<<i<<" ";
        }
    }
    cout<<endl;

    return 0;
}

int minInArray(int arr[], int arrSize) {
    int temp = arr[0];
    int lowest = temp;
    for(int i = 1; i < arrSize; i++) {
        if(arr[i] <= temp) {
            lowest = arr[i];
            temp = lowest;
        }
    }
    return lowest;
}