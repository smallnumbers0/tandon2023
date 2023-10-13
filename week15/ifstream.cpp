#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void openInputFile(ifstream& inFile) {
    string fileName;
    cout<<"What filename?"<<endl;
    cin>>fileName;
    inFile.open(fileName);

    while(!inFile) {
        cout<< "File Failed to Open"<<endl;
        cout<<"What filename?"<<endl;
        cin>>fileName;
        inFile.clear();
        inFile.open(fileName);
    }
}

struct Student {
    int id;
    double testScore;
    string name;
};

int main() {
    ifstream inFile;
    openInputFile(inFile);
    vector<Student> v;
    Student temp;
    while(inFile >> temp.id >> temp.testScore) {
        inFile >> std::ws;
        // inFile.ignore(9999, '\t');
        getline(inFile, temp.name);
        v.push_back(temp);
    }

    for(Student s: v) {
        if(s.testScore > 80) {
            cout<<s.name<<endl;
        }
    }

   

    return 0;
}