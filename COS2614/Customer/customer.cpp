#include <iostream>

using namespace std;

class Date{
public:
Date();
Date(int day, int month, int year);
int GetYear() const;
 private:
int Day;
int Month;
int Year;
};

class Person{
public:
Person(const string &name, const string &address, const Date &date);
string GetAddress() const;
string GetName() const;
protected:
string Name;
string Address;
Date DateOfBirth;

};
class Customer: public Person{
public:
Customer(const string &name, const string &address,
 const Date &date,double creditlimit);
void IncreaseLimit(double amount);
void SetBalance(double balance);
double GetBalance() const;
private:
 double CreditLimit;
 double BalanceDue;
};

class Employee: public Person{
public:
Employee(const string &name, const string &address,
 const Date &date, double rate, double hours);
double Rate;
double GetRate() const;
double GetHours() const;
private:
 double Hours;
protected:
 double Pay() const;
};

//Implementations
Date::Date()
{
    Day=0;
    Month=0;
    Year=0;
}

Date::Date(int day, int month, int year)
{
    Day=day;
    Month=month;
    Year=year;
};

int Date::GetYear() const
{
    return Year;
};

Person::Person(const string &name, const string &address, const Date &date)
{
   Name=name;
   Address=address;
   DateOfBirth=date;
};

string Person::GetAddress() const
{
    return Address;
};

string Person::GetName() const
{
    return Name;
};

Customer::Customer(const string &name, const string &address, const Date &date, double creditlimit)
:Person(name, address, date)
{
    Name=name;
    Address=address;
    DateOfBirth=date;
    CreditLimit=creditlimit;

};


void Customer::IncreaseLimit(double amount)
{
     CreditLimit=CreditLimit+amount;
};

void Customer::SetBalance(double balance)
{
    BalanceDue=balance;
};

double Customer::GetBalance() const
{
   return BalanceDue;
};

Employee::Employee(const string &name, const string &address, const Date &date, double rate, double hours)
:Person(name, address, date)
{
    Rate=rate;
    Hours=hours;
};

double Employee::GetRate() const
{

    return Rate;
};

double Employee::GetHours() const
{
    return Hours;
};


double Employee::Pay() const
{
if (DateOfBirth.GetYear() < 1967){
 return Hours*Rate;
 }
 else{
 return (Hours*Rate - (Hours*Rate*0.3));
 }
};


int main()
{
    int d=0, m=0, y=0;
    string n="", a="";
    char answer=' ';
    double cLimit=0.00, Ilimit=0.00, bal=0.00, r=0.00, h=0.00;
    cout<<"Please enter the day of birth: ";
    cin>>d;
    cout<<endl<<"Please enter the month of birth: ";
    cin>>m;
    cout<<endl<<"Please enter the year of birth: ";
    cin>>y;
    Date date1(d,m,y);
    cout<<endl<<"Please enter the individual's name: ";
    cin>>n;
    cout<<endl<<"Please enter their address: ";
    cin>>a;
    Person person(n,a,date1);

    cout<<"Is this individual a customer or a employee(Enter C or E): ";
    cin>>answer;

            if (answer=='C')
            {
            cout<<"Please enter their credit limit: ";
            cin>>cLimit;
            Customer customer1(n,a,date1,cLimit);
            cout<<endl<<"Please enter the amount to increase the credit limit(enter 0 if you dont wish to increase it): ";
            cin>>Ilimit;
            customer1.IncreaseLimit(Ilimit);
            cout<<endl<<"Enter the customer's balance: ";
            cin>>bal;
            customer1.SetBalance(bal);

            cout<<endl<<"The customer's balance is: "<<customer1.GetBalance();
            cout<<customer1.GetAddress();
            }
            else if(answer=='E')
            {


            cout<<"Enter the rate: ";
            cin>>r;
            cout<<"Enter the amount of hours: ";
            cin>>h;
            Employee employee1(n,a,date1,r,h);
            cout<<endl<<"The employee's hours: "<<employee1.GetHours();
            cout<<endl<<"The employee's rate: "<<employee1.GetRate();
            employee1.Pay();
            }
            else
            cout<<"Wrong input entered";

    cout<<"The year is "<<date1.GetYear();

    return 0;
    }




