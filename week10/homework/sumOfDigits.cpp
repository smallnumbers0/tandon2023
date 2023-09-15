//This program sums of digits using recursion.
#include <iostream>
using namespace std;


int sumDigits(int n);

int main() {
    int num = 123;
    int sum;
    sum = sumDigits(num);
    cout<<sum<<endl;
    return 0;
}
int sumDigits(int n) { //3 + 20 + 100   //theta(num of digits in n)
    //base case
    int sum = 0;
    if (n < 10) {
        return n;
    }
    else {
         int temp = sumDigits(n/10); //3, 2, 1
         return n%10 + temp;
    }
}