#include "account.h"
#include <QTextStream>

Account::Account(QString a, Customer c) : m_AccountNo(a), m_AccHolder(c), m_Balance(0.00)
{
    Transaction t("Account opened", QDate::currentDate());
    QTextStream cout(stdout);
    cout <<"Account Number: " << m_AccountNo << "\nAccount Holder: "<< m_AccHolder.toString() <<"\n"<< t.toString() << "\n\n";
    m_Transactions.append(t);
}

Account:: ~Account(){

}

void Account::deposit(double d) {
    m_Balance += d;
    Transaction t("Account credited with an amount of " + QString::number(m_Balance), QDate::currentDate());
    m_Transactions.append(t);
}

QString Account::toString() const {
    QString result = QString("Account No: %1\nAccount Holder: %2\nBalance: %3")
            .arg(m_AccountNo).arg(m_AccHolder.toString()).arg(m_Balance);
    foreach (Transaction t, m_Transactions) {
        result.append("\n").append(t.toString());
    }
    return result;
}

QList<Transaction> Account::getTransactions() const {
    return m_Transactions;
}

double Account::getBalance() const {
    return m_Balance;
}

QString Account::getAccountNo() const {
    return m_AccountNo;
}
