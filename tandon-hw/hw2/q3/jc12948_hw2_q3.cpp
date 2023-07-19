/*
Question 3:
Suppose John and Bill worked for some time and we want to calculate the total time both ofthem worked. Write a program that reads number of days, hours, minutes each of them worked, and prints the total time both of them worked together as days, hours, minutes.
Hint: Try to adapt the elementary method for addition of numbers to this use.
Your program should interact with the user exactly as it shows in the following example: 
Please enter the number of days John has worked: 2
Please enter the number of hours John has worked: 12
Please enter the number of minutes John has worked: 15
Please enter the number of days Bill has worked: 3 
Please enter the number of hours Bill has worked: 15 
Please enter the number of minutes Bill has worked: 20
The total time both of them worked together is: 6 days, 3 hours and 35 minutes.
*/

#include <iostream>
using namespace std;

int main() 
{
    int HOURS_IN_DAYS = 24, MINUTES_IN_HOURS = 60;
    int daysWorkedJohn, hoursWorkedJohn, minutesWorkedJohn, daysWorkedBill, hoursWorkedBill, minutesWorkedBill, totalDays, totalHours, totalMinutes, totalMinutesWorked, totalHoursWorked;

    cout<<"Please enter the number of days John has worked: "<<endl;
    cin>>daysWorkedJohn;

    cout<<"Please enter the number of hours John has worked: "<<endl;
    cin>>hoursWorkedJohn;

    cout<<"Please enter the number of minutes John has worked: "<<endl;
    cin>>minutesWorkedJohn;

    cout<<"Please enter the number of days Bill has worked: "<<endl;
    cin>>daysWorkedBill;

    cout<<"Please enter the number of hours Bill has worked: "<<endl;
    cin>>hoursWorkedBill;

    cout<<"Please enter the number of minutes Bill has worked: "<<endl;
    cin>>minutesWorkedBill;

    totalMinutes = minutesWorkedJohn + minutesWorkedBill;
    totalHours = hoursWorkedJohn + hoursWorkedBill;
    totalMinutesWorked = (minutesWorkedJohn + minutesWorkedBill) % MINUTES_IN_HOURS;
    totalHoursWorked = (totalHours + (totalMinutes / MINUTES_IN_HOURS)) % HOURS_IN_DAYS;
    totalDays = daysWorkedJohn + daysWorkedBill + ((totalHours) / HOURS_IN_DAYS);
   

    cout<<"The total time both of them worked together is: "<<totalDays<<" days "<<totalHoursWorked<<" hours "<<totalMinutesWorked<<" minutes "<<endl;

    return 0;
}