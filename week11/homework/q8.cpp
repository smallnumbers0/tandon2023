#include <iostream>
using namespace std;

void moveZeros(int *arr, int size);
int maxZeroLength(int *arr, int size, int startIndex);

int main() {
    int arr[6] = {0,9,0,0,2,3};
    int start = 0;
    cout<<maxZeroLength(arr, 6, start)<<endl;
    return 0;
}

void moveZeros(int *arr, int size) {
    int current = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] != 0) {
            arr[current] = arr[i];
            current++;
        }
    }
    for(int j = current; j < size; j++) {
        arr[j] = 0;
    }
}

int maxZeroLength(int *arr, int size, int startIndex) {
    if(startIndex >= 0) {
        return 0;
    }
    else {
        int count = 0;
        for(int i = startIndex; i < size; i++) {
            if(arr[i] == 0) {
                count++;
            }
        }
        return maxZeroLength(arr, size, startIndex + count);
    }
}