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

bool leapYear(int year) {
    if(year % 4 == 0 && year % 100 != 0) {
        return true;
    }
    else if(year % 400 == 0) {
        return true;
    }
    else return false;
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

int printMonthCalender(int numOfDays, int startingDay) {

    int lastDay = ((numOfDays + startingDay - 1) % 7);
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
        }
        else cout <<i<<"\t";
    }
    if(lastDay == 0) {
        lastDay++;
    }
    return lastDay;
}

void printYearCalender(int year, int startingDay) {
    int newStartDay = 0;
    for(int month = 1; month <= 12; month++) {
        if(month == 1) {
            cout<<"January, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 2) {
            cout<<"February, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            if(leapYear(year)) {
                startingDay = newStartDay;
            } else startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 3) {
            cout<<"March, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 4) {
            cout<<"April, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 5) {
            cout<<"May, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 6) {
            cout<<"June, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        } 
        else if(month == 7) {
            cout<<"July, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 8) {
            cout<<"August, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 9) {
            cout<<"September, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 10) {
            cout<<"October, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 11) {
            cout<<"November, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
        else if(month == 12) {
            cout<<"December, "<<year<<endl;
            newStartDay = printMonthCalender(getNumOfDays(month, year), startingDay);
            startingDay = newStartDay + 1;
            cout<<endl<<endl;
        }
    }
}