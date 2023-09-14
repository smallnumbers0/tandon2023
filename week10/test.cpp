#include <iostream>
using namespace std;

int* first10Squares();
void printArray(int arr[], int size);

int main() {
    int* arr; //initialize a pointer

    arr = first10Squares(); //assigns returned pointer to arr
    printArray(arr, 10);
    delete[] arr;
    return 0;
    
}

int* first10Squares() { 
    int* arr = new int[10]; //dynamically allocate memory for interger array of size 10 on the heap

    for(int i = 0; i < 10; i++) { //fills array with first 10 squares;
        arr[i] = (i+1)*(i+1);
    }

    return arr; //returns the pointer to first element of arr.
}

void printArray(int arr[], int arrSize) { //passes pointer arr and size and uses the pointer to print the integers. 
    for(int i = 0; i < arrSize; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}