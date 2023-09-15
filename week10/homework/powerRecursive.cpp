#include <iostream>
using namespace std;

int pow(int a, int n);

int main() {
    int n = 3;
    int a = 2;
    
    int power = 0;
    power = pow(a, n);
    cout<<power<<endl;
    return 0;
}


int pow(int a, int n) {
    if(n == 0) {
        return 1;
    }
    else {
        return a * pow(a, n-1);
    }
}