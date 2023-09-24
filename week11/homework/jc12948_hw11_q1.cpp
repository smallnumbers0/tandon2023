//This program prints triangles with recursion
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
using namespace std;
void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);
int main() {
    int n = 4;
    printTriangle(4);
    printOppositeTriangles(4);
    printRuler(4);
    return 0;
}

void printTriangle(int n) {
    //Base case
    if(n == 0) { 
        return;
    }
    //Recursive step
    else { 
        printTriangle(n-1);
        for(int i = 0; i < n; i++) {
            cout<<'*';
        }
        cout<<endl;
    }
}

void printOppositeTriangles(int n) {
    //Base case
    if(n == 0) {
        return;
    }
    //Recursive step;
    else {
        for(int i = 0; i < n; i++) {
            cout<<'*';
        }
        cout<<endl;
        printOppositeTriangles(n-1);
        for(int i = 0; i < n; i++) {
            cout<<'*';
        }
        cout<<endl;
    }
}

void printRuler(int n) { // n = 4    
    if(n == 0) {
        return;
    }
    else {
        printRuler(n-1);
        for(int i = 0; i < n; i++) {
            cout<<'-';
        }
    }
    cout<<endl;
    printRuler(n-1);
}
/* 
                       n = 4
                n-1          n-1
             n-2 n-2        n-2 n-2
        n-3 n-3   n-3 n-3  n-3 n-3   n-3 n-3
        0 0 0 0   0 0 0 0  0 0 0 0   0 0 0 0
*/