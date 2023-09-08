//This program reorders an array, keeping the odd numbers to the left and evens to the right and also reversing the order in for the even numbers
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
using namespace std;
void oddsKeepEvensFlip(int arr[], int arrSize);

const int SIZE = 6;
const int SIZE_A = 7;
int main() {
    int arr[SIZE] = {5, 2, 11, 7, 6, 4};
    int arr1[SIZE_A] = {11, 8, 55, 62, 101, 4, 7};
    oddsKeepEvensFlip(arr, SIZE);
    oddsKeepEvensFlip(arr1, SIZE_A);
    return 0;
}
//split into odd and even arrays
void oddsKeepEvensFlip(int arr[], int arrSize) {
    int oddArr[arrSize];
    int evenArr[arrSize];
    int oddCount = 0;
    int evenCount = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] % 2 == 0) {
            evenArr[evenCount] = arr[i];
            evenCount++;
        }
        else {
            oddArr[oddCount] = arr[i];
            oddCount++;
        }
    }
//concatenate arrays 
    for(int i = 0; i < oddCount; i++) {
        arr[i] = oddArr[i];
    }
    int count = evenCount;

    for(int i = oddCount; i < oddCount + evenCount; i++) { //add even numbers in reverse
        arr[i] = evenArr[count - 1];
        count--;
    }
    cout<<"{ ";
    for(int i = 0; i < arrSize; i++) {
        if(i == arrSize - 1) {
            cout<<arr[i];
        }
        else cout<<arr[i]<<", ";
    }
    cout<<" }"<<endl;
}
