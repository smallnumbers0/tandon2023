//This program stimulated a pin authentication by matching random numbers that maps to the pin numbers
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int encryptedPin(int num[]);

const int SECRET_PIN[5] = {8,1,1,4,5};

int main() {
    int input;
    srand(time(0));

    cout<<"Please enter the numbers corresponding to your pin: "<<endl;
    cout<<"Pin: 0 1 2 3 4 5 6 7 8 9"<<endl;
    cout<<"Num: ";

    int num[10];

    for(int i = 0; i < 10; i ++) {
        num[i] = (rand() % 3) + 1;
        cout<<num[i]<<" ";
    }

    cout<<endl;
    cin>>input;
    cout<<input<<endl;

    return 0;
}