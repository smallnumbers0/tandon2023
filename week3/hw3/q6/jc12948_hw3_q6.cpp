/*
Write a program that computes the cost of a long-distance call. The cost of the call is determined according to the following rate schedule:
• Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday, is billed at a
rate of $0.40 per minute. 
• Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday, is charged
at a rate of $0.25 per minute. 
• Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute. 
The input will consist of the day of the week, the time the call started, and the length of the call in minutes.
The output will be the cost of the call.
Notes:
1. The time is to be input in 24-hour notation, so the time 1:30 P.M. is input as 13:30 
2. The day of the week will be read as one of the following two character string: Mo Tu
We Th Fr Sa Su
3. The number of minutes will be input as a positive integer.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    const string SATURDAY = "Sa";
    const string SUNDAY = "Su";
    const int MINUTES_IN_ONE_HOUR = 60;
    const int EIGHT_AM = 8;
    const int SIX_PM = 18;
    const double WEEKEND_RATE = 0.15;
    const double TIME_DISCOUNT_RATE = 0.25;
    const double TIME_REGULAR_RATE = 0.40;

    int callLength, hours, minutes, startTime;
    char colon;
    string day;
    double rate;
    double totalCost;

    

    cout<<"Please enter the day of the week (Mo, Tu, We, Th, Fr, Sa, Su): "<<endl;
    cin>>day;
    cout<<"Please enter the time when call started in 24-hour format (18:30 for 6:30 pm): "<<endl;
    cin>>hours>>colon>>minutes;
    cout<<"Please enter duration of call in minutes: "<<endl;
    cin>>callLength;

    startTime = (hours * MINUTES_IN_ONE_HOUR) + minutes;

    if(day == "Sa" || day == "Su") {
        rate = WEEKEND_RATE;
    }
    else {

        if((startTime < EIGHT_AM * MINUTES_IN_ONE_HOUR) || (startTime > SIX_PM * MINUTES_IN_ONE_HOUR)) {
            rate = TIME_DISCOUNT_RATE;
        }
        else {
            rate = TIME_REGULAR_RATE;
        }
    }

totalCost = callLength * rate;
cout<<totalCost<<endl;

}