#include <iostream>
using namespace std;

class DayOfYear {
    public:
        void input();
        void output();
        int month;
        int day;
};

int main() {
    DayOfYear today, birthday;
    cout<<"Enter today's date: \n";
    today.input();
    cout<<"Enter your birthday date: \n";
    birthday.input();

    cout<<"Today's date is ";
    today.output();
    cout<<"Your birthday is ";
    birthday.output();

    if(today.month == birthday.month && today.day == birthday.day)
        cout<<"Happy Birthday!\n";
    else   
        cout<<"Happy Unbirthday!\n";
    return 0;
}

void DayOfYear::output(){
    cout<< "month = "<< month << ", day = " << day << endl;
}

void DayOfYear::input() {
    cout<<"Enter month as a number: ";
    cin>>month;
    cout<<"Enter the day of the month: ";
    cin>>day;
}