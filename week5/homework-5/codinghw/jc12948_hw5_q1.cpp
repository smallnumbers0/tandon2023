/*
Question 1:
Write a program that reads a positive integer n from the user and prints out a nxn
multiplication table. The columns should be spaced by a tab.
*/

// #include <iostream>

// using namespace std;

// int main() {

//     int input;

//     cout<<"Enter a positive integer: "<<endl;
//     cin>>input;

//     for(int i = 1; i <= input; i++) {
//         for(int j = 1; j <= input; j++) {
//             cout<<j * i<<" \t ";
            
//         }
//         cout<<endl;
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

int main()
{

  int n;

  cout << "Please enter a positive integer: ";
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cout << i << "\t";
    for (int j = 2; j <= n; j++)
    {
      cout << i * j << "\t";
    }
    cout << endl;
  }
  return 0;
}