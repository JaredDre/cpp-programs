#include <iostream>

using namespace std;

void printTabs()
{
    //loop calculates using i for squares and cubes
    for(int i = 1; i <= 10; i++)
    {
        cout << i << "\t" << i*i << "\t" << i*i*i << endl;
    }
}

void selTabs(int sV, int nValues, int inc)
{
    for(int i = 1; i <= nValues; i++)
    {
        cout << sV << "\t" << sV*sV << "\t" << sV*sV*sV << endl;
        sV = sV + inc;
    }
}

int main()
{
     int sValue = 0, numValues = 0, increment = 1;
     cout << "NUMBER" << '\t' << "SQUARE" << '\t' << "CUBE" << endl;
     printTabs();//void function with no parameterss to print tabs

     cout << endl;
     cout << "Enter the starting value of the table" << endl;
     cin >> sValue;
     cout << endl << "Enter the number of values to be displayed" << endl;
     cin >> numValues;
     cout << endl << "Enter the increment between the values" << endl;
     cin >> increment;

     cout<<endl;
     cout << "NUMBER" << '\t' << "SQUARE" << '\t' << "CUBE" << endl;
     selTabs(sValue,numValues,increment);

     return 0;
}
