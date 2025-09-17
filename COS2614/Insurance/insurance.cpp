#include <iostream>
#include <fstream>

using namespace std;

//declare class type
class InsurancePolicy
{
public:
 InsurancePolicy();
 InsurancePolicy(int pNr, string pHolder, double aRate);
// ~InsurancePolicy();
 void setPolicy(int pNr, string pHolder, double aRate);
 int get_pNr()const;
 string get_pHolder()const;
 double get_aRate()const;
void showPolicy(ostream & out)const;
protected:
 int policyNr;
 string policyHolder;
 double annualRate;
};

class CarInsurance: protected InsurancePolicy
{
public:
CarInsurance();
CarInsurance(int pNr, string pHolder, double aRate, double eValue);
void setPolicy(int pNr, string pHolder, double aRate, double eValue);
double get_excess()const;
void set_excess(double eValue);
void showPolicy(ostream & out)const;
private:
  double excess;

};

//Implement class
InsurancePolicy::InsurancePolicy()
{
   policyNr = 0;
   policyHolder = " ";
   annualRate = 0.0;
}

InsurancePolicy::InsurancePolicy(int pNr, string pHolder, double aRate)
{
   policyNr = pNr;
   policyHolder = pHolder;
   annualRate = aRate;
}

/*InsurancePolicy::~InsurancePolicy()
{
    cout << endl << "Goodbye!" << endl<< endl;
}*/

void InsurancePolicy::setPolicy(int pNr, string pHolder, double aRate)
{
   policyNr = pNr;
   policyHolder = pHolder;
   annualRate = aRate;
}

int InsurancePolicy::get_pNr()const
{
    return policyNr;
}

string InsurancePolicy::get_pHolder()const
{
    return policyHolder;
}

 double InsurancePolicy::get_aRate()const
{
    return annualRate;
}

CarInsurance::CarInsurance()
{
   policyNr = 0;
   policyHolder = " ";
   annualRate = 0.0;
   excess = 0.0;
}

CarInsurance::CarInsurance(int pNr, string pHolder, double aRate, double eValue)
{
   policyNr = pNr;
   policyHolder = pHolder;
   annualRate = aRate;
   excess = eValue;
}

void CarInsurance::setPolicy(int pNr, string pHolder, double aRate, double eValue)
{
    policyNr = pNr;
    policyHolder = pHolder;
    annualRate = aRate;
    excess = eValue;
}

double CarInsurance::get_excess()const
{
    return excess;
}

void CarInsurance:: set_excess(double eValue)
{
    excess = eValue;
}

 void InsurancePolicy::showPolicy(ostream & out)const
 {
    //InsurancePolicy& tempPolicy1;
    out<<"Policy Number: "<<get_pNr()<<endl<<"Policy Holder: "<<get_pHolder()<<endl<<"Annual Rate: "<<annualRate<<endl<<endl;
 }

 void CarInsurance::showPolicy(ostream & out)const
 {
     CarInsurance tempPolicy2;
    out<<"Policy Number: "<<get_pNr<<endl<<"Policy Holder: "<<policyHolder<<endl<<"Annual Rate: "<<annualRate<<endl<<"Excess: "<<excess<<endl<<endl;
 }

 int main()
{
 InsurancePolicy myPolicy(123456, "Peter Molema", 3450.67);
 CarInsurance yourPolicy(456891, "Wilson Ntemba", 5550.67, 15000.00);
 cout.setf(ios::fixed);
 cout.setf(ios::showpoint);
 cout.precision(2);
 myPolicy.showPolicy(cout);
 cout << endl;
 yourPolicy.showPolicy(cout);
 cout << endl << "AFTER UPDATES:" << endl;
 myPolicy.setPolicy(123456, "Peter Molema", 5450.67);
 yourPolicy.setPolicy(456891, "Wilson Ntemba", 6650.67,
25000.00);
 myPolicy.showPolicy(cout);
 cout << endl;
 yourPolicy.showPolicy(cout);
 cout << endl;
 return 0;
}
