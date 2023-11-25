#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void vsort(vector<int> &nums, vector<string> &names) {
    int n = nums.size();
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int tempNum = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tempNum;
                
                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }
}


int main() {
    string file_name;
    ifstream input_file;
    cout<<"Enter file name: "<<endl;
    cin>>file_name;
    input_file.open(file_name);

    while(!input_file) {
        cout<<"Error"<<endl;
        cout<<"Enter file name: "<<endl;
        cin>>file_name;
        input_file.clear();
        input_file.open(file_name);
    }
    vector<int> num;
    vector<string> name;
    int numTemp;
    string temp;
    while(input_file >> numTemp) {
        num.push_back(numTemp);
        input_file.ignore(3, '\t');
        input_file >> temp;
        name.push_back(temp);
    }
    vsort(num, name);

    for(int i = 0; i < name.size(); i++) {
        cout<<num[i]<<'\t';
        cout<<name[i]<<endl;
    }
    ofstream out_file;
    out_file.open("Input.txt");

    for(int i = 0; i < num.size(); i++) {
        out_file << num[i] << '\t';
        out_file << name[i]<<endl;
    }
}