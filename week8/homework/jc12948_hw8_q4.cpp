//This program stimulated a pin authentication by matching random numbers that maps to the pin numbers
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int encryptedPin(int num[]);
int pinEntry(int num[]);

const int SECRET_PIN[5] = {8,1,1,4,5};

int main() {
    int num[10];
    srand(time(0));
    int entry = pinEntry(num);

    if (entry == encryptedPin(num)) {
        cout << "Your pin is correct."<<endl;
    } else {
        cout << "Your pin is not correct."<<endl;
    }


    return 0;
}

int pinEntry(int num[]) {
    int input;
    cout<<"Please enter the numbers corresponding to your pin: "<<endl;
    cout<<"Pin: 0 1 2 3 4 5 6 7 8 9"<<endl;
    cout<<"Num: ";

     for(int i = 0; i < 10; i ++) {
        num[i] = (rand() % 3) + 1;
        cout<<num[i]<<" ";
    }

    cout<<endl;
    cin>>input;
    cout<<input<<endl;

    return input;
}

int encryptedPin(int num[]) {
    int encryptedPin = 0;
    for(int i = 0; i < 5; i++) {
        encryptedPin = 10 * encryptedPin + num[SECRET_PIN[i]];
    }
    return encryptedPin;
}