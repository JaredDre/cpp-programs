#include "customer.h"

Customer::Customer(QString n, QString i) : m_Name(n), m_ID(i)
{
}

QString Customer::toString() const {
    return "\nCustomer Name: " + m_Name + "\nCustomer ID: " + m_ID;
}
