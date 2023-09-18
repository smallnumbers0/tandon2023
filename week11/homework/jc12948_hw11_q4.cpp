#include <iostream>
using namespace std;

int jumpIt(int arr[], int size);

int main() {
    const int size = 8;
    int arr[size] = {0, 3, 1, 1, 4, 10, 10, 2};
    cout<<jumpIt(arr, size)<<endl;
    return 0;
}

int jumpIt(int arr[], int size) {
    if(size <= 2) {
        return arr[size-1];
    }
    else {
        int adjacentOne = jumpIt(arr, size - 1);
        int adjacentTwo = jumpIt(arr, size - 2);
        if( adjacentOne > adjacentTwo) {
            return adjacentTwo + arr[size-1];
        }
        return arr[size-1] + jumpIt(arr, size-1);
    }
}