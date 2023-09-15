#include <iostream>
using namespace std;

void printAscAndDec(int start, int end);

int main() {
    int start = 1;
    int end = 4;
    printAscAndDec(start, end);
    return 0;
}

void printAscAndDec(int start, int end) {
    if(start == end) {
        cout<< start<<endl;
    }
    else {
        cout<<start<<endl;
        printAscAndDec(start+1,end);
        cout<<start<<endl;
    }
}
