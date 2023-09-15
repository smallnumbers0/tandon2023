//This function does factorial using recursion

#include <iostream>
using namespace std;

int factorial(int n);

int main() {
    int n = 5;
    int result;
    result = factorial(n);
    cout<<result<<endl;
    return 0;
}
int factorial(int n) {//5 x 4 x 3 x 2 x 1
    if(n == 1) {
        return n;
    }
    else {
       return n * factorial(n-1);
    }
}