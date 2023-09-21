#include <iostream>
using namespace std;

int findMax(vector <int> studentGrades);

int main() {
    int id;
    int grade;
    vector <int> idNums;
    vector <int> studGrades;
    cout<<"Please enter a non-empty sequence of lines.\n Each line should have a student ID and their grade (0-100), separated by a space.\n To indicate the end of the input, enter -1 as a student ID: "<<endl;
    while(true) {
        cin>>id;
        if(id == -1) {
            break;
        }
        cin>>grade;
        idNums.push_back(id);
        studGrades.push_back(grade);
    }
 
    // int max = studGrades[0];
    // for(int i = 1; i < studGrades.size(); i++) {
    //     if(max < studGrades[i]) {
    //         max = studGrades[i];
    //     }
    // }
    int max = findMax(studGrades);

    cout<<"The students with the highest grades are: "<<endl;
    for(int i = 0; i < studGrades[i]; i++) {
        if(max == studGrades[i]) {
            cout<<idNums[i]<<" "<<studGrades[i]<<endl;
        }
    }


    return 0;
}

int findMax(vector <int> studentGrades) {
    int max = studentGrades[0];
        for(int i = 1; i < studentGrades.size(); i++) {
            if(max < studentGrades[i]) {
                max = studentGrades[i];
        }
    }
    return max;
}