#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void openFile(ifstream &input_file) {
    string file_name;
    cout<<"Enter file name: "<<endl;
    cin>>file_name;
    input_file.open(file_name);

    while(!input_file) {
        cout<<"Error"<<endl;
        cout<<"Enter file name again."<<endl;
        cin>>file_name;
        
        input_file.clear();
        input_file.open(file_name);
    }

}

void vsort(vector<int> &nums, vector<string>&names) {
    int numTemp;
    string nameTemp;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] > nums[j]) {
                numTemp = nums[i];
                nums[i] = nums[j];
                nums[j] = numTemp;

                nameTemp = names[i];
                names[i] = names[j];
                names[j] = nameTemp;

            }
        }
    }
}

void outFile(vector<int> nums, vector<string> names, ofstream &out_file) {
    out_file.open("output.txt", ios::app);
    for(int i = 0; i < nums.size(); i++) {
        out_file << nums[i];
        out_file << '\t';
        out_file << names[i]<<endl;
    }
}

int main() {
    ifstream input_file;
    openFile(input_file);
    int num;
    string name;
    vector<int> nums;
    vector<string> names;

    while(input_file >> num) {
        nums.push_back(num);
        input_file.ignore(9999, '\t');
        input_file >> name;
        names.push_back(name);
    }

    vsort(nums, names);

    for(int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<"\t"<<names[i]<<endl;
    }

    ofstream output_file;
    outFile(nums,names,output_file);

    input_file.close();
    output_file.close();

    return 0;
}