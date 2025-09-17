#include "transaction.h"

Transaction::Transaction(QString c, QDate d) : m_Description(c), m_Date(d)
{
}

QDate Transaction::getDate() const {
    return m_Date;
}

QString Transaction::toString() const {
    return QString("Transaction: %1\tDate of Transaction: %2").arg(m_Description).arg(m_Date.toString());
}
