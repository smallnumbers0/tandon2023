#include <iostream>
#include <cmath>
using namespace std;

bool checkPalindrome(int num);

int main() {
    int input;
    cout<<"Please enter a positive integer: "<<endl;
    cin>>input;

    int result = checkPalindrome(input);
    if(result == 1) {
        cout<<"Palindrome"<<endl;
    }
    else cout<<"Not Palindrome"<<endl;

    return 0;
}

bool checkPalindrome(int num) {
    //313 % 10 = 3
    //313 / 10 = 31
    //31 % 10 = 1
    //31 / 10 = 3
    //3 % 10 = 3
    int digit = 0;
    int result = 0;
    int count = 0;
    int temp = num;
    while(temp > 0) {
        digit = temp % 10;
        result += digit * pow(10, count);
        count++;
        temp /= 10;
        cout<<result<<endl;
    }
    return result == num;
}