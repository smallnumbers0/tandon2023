//This program reorders an array, keeping the odd numbers to the left and evens to the right and also reversing the order in for the even numbers
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

const int SIZE = 6;
int main() {
    int arr[SIZE] = {5, 2, 11, 7, 6, 4};

    oddsKeepEvensFlip(arr, SIZE);

    return 0;
}

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

    for(int i = 0; i < evenCount/2 - 1; i++) {
        int temp = evenArr[i];
        evenArr[i] = evenArr[evenCount];
        evenArr[evenCount] = temp;
    }
    for(int i = 0; i < oddCount; i++) {
        arr[i] = oddArr[i];
    }
    for(int i = oddCount; i < oddCount + evenCount -1; i++) {
        arr[i] = evenArr[i];
    }

    for(int i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
