#include<iostream>
using namespace std;

void printReport(string* burritosPtr, int* salesPtr, int numTypes);

int main(void) {
  int numTypes;
  cout << "How many types of burritos did you sell today? ";
  cin >> numTypes;

  string* names = new string[numTypes];
  int* numSold = new int[numTypes];
  cout << sizeof(names) << " " << sizeof(numSold) << endl;
  printReport(names, numSold, numTypes);

  delete [] names;
    names = nullptr;
  delete [] numSold;
 numSold = nullptr;

if(names == nullptr) {
    cout<<"done"<<endl;
}
if(numSold == nullptr) {
    cout<<"done"<<endl;
}
  
  cout << (sizeof(names)) << " " << sizeof(numSold) << endl;
  return 0;
}

void printReport(string* burritosPtr, int* salesPtr, int numTypes) {
  for (int i = 0; i < numTypes; i++)
  {
    cout << "Enter type for burrito " << i + 1 << ": ";
    cin >> *(burritosPtr + i);
    cout << "Enter number of " << *(burritosPtr + i) << " sold: ";
    cin >> *(salesPtr + i);
  }

  for (int i = 0; i < numTypes; i++)
    cout << *(burritosPtr + i) << ": " << *(salesPtr + i) << endl;
}