#include "savings.h"

Savings::Savings(QString a, Customer c) : Account(a,c)
{
}

bool Savings::withdraw(double d) {
    if(getBalance() >= d) {
        double newBalance = getBalance() - d;
        Transaction t("Savings Account withdrawal with a current amount of " + QString::number(newBalance), QDate::currentDate());
        m_Transactions.append(t);
        m_Balance=newBalance;
        return true;
    }
    else
        return false;
}

QString Savings::toString() const {
    return Account::toString() + "\nInterest Rate: " + QString::number(INTEREST);
}
 //add interst
