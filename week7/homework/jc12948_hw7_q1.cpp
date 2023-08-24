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

    printYearCalender(year, startingDay);

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
        if((i + startingDay - 1) % 7 == 0 || i == numOfDays) {
            cout <<i<<endl;
        }
        else cout <<i<<"\t";
    }
    if(lastDayOfWeek == 0) { 
        lastDayOfWeek = 7;
    }
    return lastDayOfWeek;
}

void printYearCalender(int year, int startingDay) {
    for(int i = 1; i <= 12; i++) {
        if(i == 1) {
            cout<<"January, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 2) {
            cout<<"February, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 3) {
            cout<<"March, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 4) {
            cout<<"April, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 5) {
            cout<<"May, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 6) {
            cout<<"June, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        } 
        else if(i == 7) {
            cout<<"July, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 8) {
            cout<<"August, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 9) {
            cout<<"September, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 10) {
            cout<<"October, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 11) {
            cout<<"November, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
        else if(i == 12) {
            cout<<"December, "<<year<<endl;
            startingDay = printMonthCalender(getNumOfDays(i, year), startingDay);
            cout<<endl<<endl;
        }
    }
}