#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
#include <QList>
#include "customer.h"
#include "transaction.h"

class Account
{
public:
    Account(QString a, Customer c);
    virtual ~Account();
    void deposit(double d);
    virtual bool withdraw(double d)=0;
    virtual QString toString() const;
    QList<Transaction> getTransactions() const;
    double getBalance() const;
    QString getAccountNo() const;
private:
    QString m_AccountNo;
    Customer m_AccHolder;
protected:
    double m_Balance;
    QList <Transaction> m_Transactions;
};

#endif // ACCOUNT_H
