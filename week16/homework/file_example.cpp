//This program opens a file
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	string fileName;
	ifstream inputFile;
	cout << "Enter the file name: " << endl;
	cin >> fileName;
	inputFile.open(fileName);
	vector <string> v;
	while(!inputFile) {
			cout << "File not found" <<endl;
			cout << "Enter the file name: " << endl;
			cin >> fileName;
	
			inputFile.clear();
			inputFile.open(fileName);
	}
	string temp;
	while(getline(inputFile, temp)) {
			v.push_back(temp);
	}
	for(int i = 0; i < v.size(); i++) {
			cout<<v[i]<<endl;
	}
	return 0;
}