//This program sums all numbers in array using recursion

#include <iostream>
using namespace std;

int sumArr(int *arr, int size);

int main() {
    int size = 6;
    int arr[6] = {1,5,5,5,5,1} ;
    int sum;
    sum = sumArr(arr, size);
    cout<<sum<<endl;
    return 0;
}

int sumArr(int *arr, int size) {
    if(size == 1) {
        return arr[0];
    }
    else {
        return arr[size - 1] + sumArr(arr, size-1);
        
    }
    
}
//T_sumArray(n) = theta(1) + theta(1)...... + theta(1) + theta(n)
//== theta(n);
