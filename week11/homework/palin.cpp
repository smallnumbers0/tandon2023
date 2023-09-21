#include <iostream>
using namespace std;

int palin(int* arr, int size);
int main() {
    int arr[6] = {4,3,6,6,5,1};

    int size = 6;

    cout<<palin(arr, size)<<endl;
  
    return 0;
}

int palin(int* arr, int size) { //
    if(size == 0) {
        return 0;
    }
    else {
        int count = 0;
        if(arr[0] != arr[size-1]) {
            count++;
        }
        return count + palin(arr + 1, size - 2);
    }
}

