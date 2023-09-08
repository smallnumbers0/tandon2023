//This program gets the positive numbers of an array in 4 different ways.
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
using namespace std;


void printArray(int arr[], int arrSize);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSize);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArr, int* outPosArrSize);



int main() {
    const int SIZE = 6;
    int arr[SIZE] = {3, -1 -3, 0, 6, 4};
    int outPosArrSize;
    int* newArr1;
    int* newArr2;  
    int* newArr3 = nullptr;  
    int* newArr4 = nullptr;  

    newArr1 = getPosNums1(arr, SIZE, outPosArrSize);
    cout<<"Updated Array Size: "<<outPosArrSize<<endl;
    printArray(newArr1, outPosArrSize);

    newArr2 = getPosNums2(arr, SIZE, &outPosArrSize);
    cout<<"Updated Array Size: "<<outPosArrSize<<endl;
    printArray(newArr2, outPosArrSize);

    getPosNums3(arr, SIZE, newArr3, outPosArrSize);
    cout<<"Updated Array Size: "<<outPosArrSize<<endl;
    printArray(newArr3, outPosArrSize);

    getPosNums4(arr, SIZE, &newArr4, &outPosArrSize);
    cout<<"Updated Array Size: "<<outPosArrSize<<endl;
    printArray(newArr4, outPosArrSize);

    delete[] newArr1;
    delete[] newArr2;
    delete[] newArr3;
    delete[] newArr4;
    
    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int newSize = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            newSize++;
        }
    }

    int* newArr = new int[newSize];
    int newArrIndex = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            newArr[newArrIndex] = arr[i];   
            newArrIndex++;
        }
    }
    outPosArrSize = newSize;
    return newArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSize) {
    int newSize = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            newSize++;
        }
    }
    int* newArr = new int[newSize];
    int newArrIndex = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            newArr[newArrIndex] = arr[i];   
            newArrIndex++;
        }
    }
    *outPosArrSize = newSize;
    return newArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int newSize = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            newSize++;
        }
    }
    outPosArr = new int[newSize];
    int newArrIndex = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            outPosArr[newArrIndex] = arr[i];   
            newArrIndex++;
        }
    }
    outPosArrSize = newSize;
    
}

void getPosNums4(int* arr, int arrSize, int** outPosArr, int* outPosArrSizePtr) {
    int newSize = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            newSize++;
        }
    }
    int* newArr = new int[newSize];
    int newArrIndex = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            newArr[newArrIndex] = arr[i];   
            newArrIndex++;
        }
    }
    *outPosArr = newArr;
    *outPosArrSizePtr = newSize;
    
}

void printArray(int arr[], int arrSize) {
    cout<<"{";
    for (int i = 0; i < arrSize; i++) {
        if(i < arrSize-1) {
            cout<<arr[i]<<", ";
        }
        else {
            cout<<arr[i];
        }
    }
    cout<<"}"<<endl;
}