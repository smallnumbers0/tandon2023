#include <iostream>
using namespace std;


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

    for(int i = 0; i < idNums.size(); i++) {
        cout<<idNums[i]<<" "<<studGrades[i]<<endl;
    }
 

    return 0;
}