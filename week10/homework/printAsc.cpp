//This program prints numbers in ascending order

#include <iostream>
using namespace std;


void printasc(int start, int end);
int main() {
    int start = 3;
    int end = 6;

    printasc(start,end);


    return 0;
}

void printasc(int start, int end) {
    if(start==end) { //check if 3 == 6
        cout<<start<<endl;
    }
    else {
        int middle;
        middle = (start+end)/2;
        printasc(start, middle);
        printasc(middle+1, end);
    }
}