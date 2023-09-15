//This program stores a sequence of integers from an user input into an array for main1 and vector for main2.
//It also asks the user for a numer they want to search for and prints out the position of the number.
//Jacky Choi NYU Tandon Summer 2023


#include <iostream>
#include <vector>
using namespace std;

void main1();
void main2();

int main() {
    main2();
    return 0;
}

void main1() { //This function does not use vector
    int size = 0;
    int* arr = new int[size];
    //use a ptr to create dynamic memory heap
    //we increment size for every input
    //an input of -1 stops sequence
    cout<<"Please enter a sequence of integers and -1 to stop: "<<endl;
    int input = 0;
    while(input != -1) {
        cin>>input;
        if(input == -1) { 
            break; //break here so -1 is not in array.
        }
        arr[size] = input;
        size++;
    }

    cout<<"Please enter an integer to find its location."<<endl;
    cin>>input;
    bool found = false;
    for(int i = 0; i < size; i++) {
        if(arr[i] == input) {
            found = true;
        }
    }
    if(found == true) { //set to true to start printing where nums are found
        cout<<input<<" is found in line(s): ";
    }
    else {
        cout<<input<<" is not found anywhere in the sequence.";
    }
    for(int i = 0; i < size; i++) {
        if(arr[i] == input) {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;

    delete[] arr;
    arr = NULL;
}

void main2() {
    vector<int> nums;
    
    int input = 0;
    cout<<"Please enter a sequence of integers and -1 to stop: "<<endl;
    while(input != -1) {
        cin>>input;
        if(input == -1) {
            break;
        }
        nums.push_back(input);
    }

    for(int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<endl;
    }
}