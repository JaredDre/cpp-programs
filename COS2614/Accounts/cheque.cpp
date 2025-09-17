#include "cheque.h"

Cheque::Cheque(QString a, Customer c, double o) : Account(a,c), m_Overdraft(o)
{
}

bool Cheque::withdraw(double d) {
    if((getBalance() + m_Overdraft) >= d) {
        double newBalance = getBalance() - d;
        Transaction t("Cheque Account withdrawal with a current amount of " + QString::number(newBalance), QDate::currentDate());
        m_Transactions.append(t);
        m_Balance=newBalance;
        return true;
    }
    else
        return false;
}

QString Cheque::toString() const {
    return Account::toString() + "\nOverdraft: " + QString::number(m_Overdraft, 'f', 2);
}
