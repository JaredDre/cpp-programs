#include "accountlist.h"
#include <QTextStream>
#include <QStringList>


void AccountList::addAccount(Account* a)
{
    this->append(a);
}

void AccountList::displayList() const {
    QTextStream cout(stdout);
    foreach(Account *a, *this) {
        cout << a->toString() << endl << endl;
    }
}

void AccountList::displayAccounts(QDate d) const {
    QTextStream cout(stdout);
    cout <<"Account transactions recorded today" << "\n";
     foreach(Account *a, *this) {
         cout << "For Account Number " << a->getAccountNo() << ":\n";
         foreach(Transaction t,a->getTransactions()){
             if(t.getDate()==d)
                cout << t.toString() << "\n";
         }//for each-t
     }//for each-a
}

int AccountList::countAccounts(double d) const {
    int AccCount=0;

    for(int i =0; i < size(); i++){
        if(at(i)->getBalance()>d){
           AccCount++;
        }//if
    }//for
    return AccCount;
}

void AccountList::deleteAll() {
    qDeleteAll(*this);
}
