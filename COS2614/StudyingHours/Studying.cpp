
// This program finds the average time spent programming and biology by a student
// each day over a n-day period.
#include <iostream>
using namespace std;
int main()
{
int numStudents, numDays;
float pNumHours, pTotal, pAverage, bNumHours, bTotal, bAverage;
int student,day = 0; // these are the counters for the loops
cout << "This program will find the average number of hours a day"
<< " that a student spent programming and studying biology over any amount of days";
cout << endl << "How many students are there?" << endl << endl;
cin >> numStudents;
cout << "Please enter the amount of days the student studied over." << endl;
cin >> numDays;
for(student = 1; student <= numStudents; student++)
{
pTotal = 0;
bTotal=0;
for(day = 1; day <= numDays; day++)
{
cout << endl << "Please enter the number of hours studying programming worked by student "
<< student <<" on day " << day << "." << endl;
cin >> pNumHours;
pTotal = pTotal + pNumHours;

cout << endl << "Please enter the number of hours studying biology worked by student "
<< student <<" on day " << day << "." << endl;
cin >> bNumHours;
bTotal = bTotal + bNumHours;

}//for loop numDays
pAverage = pTotal / numDays;
bAverage = bTotal / numDays;

cout.setf(ios::fixed);
cout.precision(2);
cout << endl;
cout << "The average number of hours per day spent programming "
<< "by student " << student << " is " << pAverage << " hours"
<< endl << endl << endl;
cout << "The average number of hours per day spent studying biology "
<< "by student " << student << " is " << bAverage << " hours"
<< endl << endl << endl;

if (pAverage>bAverage)
    cout << "The student has spent more hours on programming on average" << endl << endl;
else if (pAverage<bAverage)
    cout << "The student has spent more hours on studying biology on average" << endl << endl;
else
    cout << "The student has spent the same amount of hours on studying biology and programming on average" << endl << endl;
}//for loop numStudents
return 0;
}
