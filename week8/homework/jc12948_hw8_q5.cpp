//This program takes in a name in one format: First/Middle/Last and prints it out in another format: Last/First/Middle
//Jacky Choi NYU Tandon Bridge Summer 2023

#include <iostream>
using namespace std;

int main() {
    string first, middle, last;

    cout<<"Please enter your name in the following format seperated by a space: (First Middle Last): "<<endl;
    cin>>first>>middle>>last;
    middle = middle[0];
    cout<<last<<", "<<first<<" "<<middle<<"."<<endl;
}