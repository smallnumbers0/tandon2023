//This function takes an array of integers and determins if they are all even using recursion

#include <iostream>
using namespace std;

bool allEven(int arr[], int n);

int main() {
    int size = 5;
    int arr[5] = {4, 6, 8, 1, 10};
    cout<<allEven(arr, size)<<endl;
    cout<<3/2<<endl;
    return 0;
}

bool allEven(int arr[], int n) {
    if(n == 1) {
        if(arr[0] % 2 == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        bool temp;
        temp = allEven(arr, n-1);
        if( temp == true) {
            return (arr[n-1]%2 == 0);
        }
        else return false;
    }
}

