#include <iostream>
using namespace std;

int jumpIt(int arr[], int start, int size);

int main() {
    const int size = 6;
    int start = 0;
    int arr[size] = {0, 3, 80, 6, 57, 10};
    cout<<jumpIt(arr, start, size)<<endl;
    return 0;
}

int jumpIt(int arr[], int start, int size) {
    if(start == size) {
        return 0;
    }
    else {

        int next = jumpIt(arr, start+1, size);
        if(next <= arr[start+1]) {
            return next;
        }
        return next + jumpIt(arr, start+1, size);
    }
}