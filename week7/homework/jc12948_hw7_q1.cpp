/*
Question 1: Print Monthly Calender Function
Jacky Choi 08/20/2023
jc12948 hw 7 q1
*/

#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
void printYearCalender(int year, int startingDay);
bool leapYear(int year);
int getNumOfDays(int month, int year);

int main() {
    int startingDay = 0;
    int year = 0;

    cout<<"Please enter an integer corresponding to the starting day. (Ex: 3 for Wednesday): ";
    cin>>startingDay;
    cout<<"Please enter the year: ";
    cin>>year;

    printMonthCalender(31, startingDay);
    //printYearCalender(year, startingDay);

    return 0;
}

int getNumOfDays(int month, int year) {
    int numOfDays = 0;

    if(month == 2) {
        if(leapYear(year) == false) {
            numOfDays = 28;
        }
        else numOfDays = 29;
        }
    else if(month == 4 || month == 6 || month == 9 || month == 11) {
        numOfDays = 30;
    }
    else numOfDays = 31;
    return numOfDays;
}

bool leapYear(int year) {
    if(year % 4 == 0 && year % 100 != 0) {
        return true;
    }
    else if(year % 400 == 0) {
        return true;
    }
    else return false;
}

int printMonthCalender(int numOfDays, int startingDay) {

    int lastDayOfWeek = (numOfDays + startingDay - 1) % 7;
    cout <<"Mon"<<"\t";
    cout <<"Tue"<<"\t";
    cout <<"Wed"<<"\t";
    cout <<"Thu"<<"\t";
    cout <<"Fri"<<"\t";
    cout <<"Sat"<<"\t";
    cout <<"Sun"<<"\t";
    cout <<endl;
    for(int i = 1; i < startingDay; i++) {
        cout<<"\t";
    }
    for(int i = 1; i <= numOfDays; i++) {
        if((i + startingDay - 1) % 7 == 0) {
            cout <<i<<endl;
            if(i == numOfDays) {
                cout <<i<<endl;
            }
        }
        else cout <<i<<"\t";
    }
    if(lastDayOfWeek == 0) { //Temporary fix to testing (28,1) 
        lastDayOfWeek = 7;
    }
    return lastDayOfWeek;
}