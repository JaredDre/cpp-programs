#include <QCoreApplication>
#include "account.h"
#include "accountlist.h"
#include "cheque.h"
#include "savings.h"
#include <QTextStream>
#include <QtGlobal>
#include <QTime>

QTextStream cout(stdout, QIODevice::WriteOnly);
QTextStream cin(stdin, QIODevice::ReadOnly);


int main()
{
       AccountList a1;
       Customer cust1("M Salah", "3246873464");
       a1.addAccount(new Cheque("1111",cust1,2500));
       Customer cust2("D Nunez", "5384573949");
       a1.addAccount(new Cheque("2222",cust2,3000));
       Customer cust3("R Firmino", "7348579434");
       a1.addAccount(new Cheque("3333",cust3,4800));
       Customer cust4("D.Jota", "0543789533");
       a1.addAccount(new Savings("4444",cust4));
       Customer cust5("L Diaz", "7667465376");
       a1.addAccount(new Savings("5555",cust5));
       Customer cust6("S Gerrard", "3289723939");
       a1.addAccount(new Savings("6666",cust6));
       cout << "Accounts Have Been Added" << endl;

       cout << endl << "Displaying Accounts";
       cout << endl<<endl;
       a1.displayList();
       cout << endl;

       cout << "Deposits and Withdrawals on Accounts";
       cout << endl << endl;
       int num1 = 10000;
       int num2 = 1020;

       for (int i =0; i <a1.size(); i++){
              a1.at(i)->deposit(num1);
              cout << "Account number: " << a1.at(i)->getAccountNo()
                   << " Balance after deposit: " << a1.at(i)->getBalance();
              a1.at(i)->withdraw(num2);
                     cout << endl;
                     cout << "Account number: " << a1.at(i)->getAccountNo()
                          << " Balance after withdrawal: " << a1.at(i)->getBalance()<< endl << endl;
              num1 +=100;
              num2 +=10;
       }

       cout << "Displaying Accounts after transactions";
       cout << endl<<endl;
       a1.displayList();

       QDate date=QDate::currentDate();
       a1.displayAccounts(date);
       double num3=9000;
       int countAcc=a1.countAccounts(num3);
       cout << "\nCustomers with higher balances than R8000: " << countAcc <<"\n";

       return 0;

}
