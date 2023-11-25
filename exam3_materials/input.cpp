#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void openFile(ifstream &input_file) {
    string file_name;
    cout<<"Enter the name of file: "<<endl;
    cin>>file_name;

    input_file.open(file_name);
    while(!input_file) {
        cout<<"Error"<<endl;
        cout<<"Enter the name of file again: "<<endl;
        cin>>file_name;
        input_file.clear();
        input_file.open(file_name);
    }
}

void outFile(vector<int> nums, vector<string> names) {
    ofstream out_file;
    out_file.open("result.txt");

    for(int i = 0; i < nums.size(); i++) {
        out_file<<nums[i]<<'\t'<<names[i]<<endl;
    }
}

int main() {
    vector<int> nums;
    vector<string> names;
    int num;
    string name;
    ifstream input_file;
    openFile(input_file);
    while(input_file>>num) {
        nums.push_back(num);
        input_file.ignore(9999, '\t');
        input_file>>name;
        names.push_back(name);
    }

    outFile(nums, names);
    return 0;
}