#include <iostream>
using namespace std;

int main()
{
  int input;
  int seq;
  int numberOfDigits = 0;
  int reminder;

  int groupThree = 0;
  int groupFour = 0;
  int groupFive = 0;
  int groupSix = 0;
  int groupSeven = 0;

  int odd = 0;
  int even = 0;

  int groupOdd = 0;
  int groupEqual = 0;

  cout << "Please enter a sequence of numbers (with at least 3-digits and at most 7- digits), each one in a separate line. End your sequence by typing -1: " << endl;
  // cout << "Please enter a sequence of numbers in between 1 and 100, each one in a separate line. End your sequence by typing -1: " << endl;
  // first digit cannot be zero

  cin >> input;

  // run through every input entered until -1 to end

  while (input != -1)
  {
      // reset values for each new input seq
    odd = 0;
    even = 0;
    numberOfDigits = 0;

    seq = input;

    // count digits in each sequence and check parity of each digit
    while (seq > 0)
    {
      reminder = seq % 10;
      seq = seq / 10;
      numberOfDigits++;

      // check digit even or odd
      if (reminder % 2 == 1)
      {
        odd++;
      }
      else if (reminder % 2 == 0)
      {
        even++;
      }
    }

    // count numbers group
    if (numberOfDigits == 3)
    {
      groupThree++;
    }
    else if (numberOfDigits == 4)
    {
      groupFour++;
    }
    else if (numberOfDigits == 5)
    {
      groupFive++;
    }
    else if (numberOfDigits == 6)
    {
      groupSix++;
    }
    else if (numberOfDigits == 7)
    {
      groupSeven++;
    }

    // odd or equal groups
    if (odd > even)
    {
      groupOdd++;
    }
    else if (even == odd)
    {
      groupEqual++;
    }
    cin >> input;
  }

  cout << "Total count of numbers in the 3-digits Numbers group: " << groupThree << endl;
  cout << "Total count of numbers in the 4-digits Numbers group: " << groupFour << endl;
  cout << "Total count of numbers in the 5-digits Numbers group: " << groupFive << endl;
  cout << "Total count of numbers in the 6-digits Numbers group: " << groupSix << endl;
  cout << "Total count of numbers in the 7-digits Numbers group: " << groupSeven << endl;
  cout << "Total count of numbers in the More Odd-digits group: " << groupOdd << endl;
  cout << "Total count of numbers in the Equal-digits group: " << groupEqual << endl;

  return 0;
}