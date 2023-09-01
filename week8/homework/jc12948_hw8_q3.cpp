//This program have 3 special functions that remove all odd nums, reverses array, and splits array from even and odd
//Jacky Choi NYU Tandon Bridge Summer 2023
#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);


int main() {
    int arr1[10] = {1,2,3,4,5};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    
    return 0; 
}

void printArray(int arr[], int arrSize) {
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void reverseArray(int arr[], int arrSize) {
    int j = 0;
    int temp = 0;
    for(int i = arrSize - 1; i > arrSize/2; i--) {
        temp = arr[i]; //temp = 5   //temp = 4
        arr[i] = arr[j];  //arr[4] = 1 //arr[3] = 2
        arr[j] = temp; //arr[0] = 1 //arr[1] = 4
        j++; //j = 1
    }
    cout<<"reverse"<<endl;
}
void removeOdd(int arr[], int& arrSize) {
    int j = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] % 2 == 0) {
            arr[j] = arr[i];  
            j++;      
        }
    }
    arrSize = j;
}
void splitParity(int arr[], int arrSize) { //[1, 2, 3, 4] to [3, 1, 2, 4]
    int j = arrSize - 1;
    int temp = 0;
    int k = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] % 2 == 0) { //if number is even
            temp = arr[j];
            arr[j] = arr[i]; //swap to the end
            arr[i] = temp;
            j--;
        }
    }
    for(int i = 0; i < arrSize; i++) {
         if(arr[i] % 2 != 0) { //if number is odd
            temp = arr[k];
            arr[k] = arr[i];  //swap to the front
            arr[i] = temp;
            k++;
        }
    }
}

