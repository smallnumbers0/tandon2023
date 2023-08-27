#include <iostream>
using namespace std;

const int MAX_CLASS_SIZE = 60;

int main() {
    int numStudents;
    int gradesList[MAX_CLASS_SIZE];
    int currGrade;
    int sum = 0;
    double average;

    cout<<"please enter the number of students in the class: "<<endl; //this lets the user input the amount of students
    cin>>numStudents;
    cout<<"Please enter the grades of each student: "<<endl;

    for(int i = 0; i < numStudents; i++) { //this will loop over the amount of students
        cin>>currGrade;
        gradesList[i] = currGrade; //this updates the grade in each index of the array
    }

    for(int i = 0; i < numStudents; i++) {
        sum += gradesList[i];
    }
    average = (double)sum / (double)numStudents;
    cout<<"The average is: "<<average<<endl;
    cout<<"Above average grades: "<<endl;

    for(int i = 0; i < numStudents; i++) {
        if(gradesList[i] > average) {
            cout<<gradesList[i]<<endl;
        }
    }

    return 0;
}