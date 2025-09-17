#include "Squab.h"
#include <QDebug>

Squab::Squab(int x, int y){
score=0;
new Position(x,y);
}

int Squab::getScore()const{
    return score;
}

void Squab::incScore(){
    score++;
}

Position Squab::getPos()const{
    return *pos;
}

void Squab::move(char dn, int de){
    switch (dn)
    {
    case 'N':
    case 'n':
        pos->changePos(pos->getX(),pos->getY()+de);
        break;
    case 'S':
    case 's':
        pos->changePos(pos->getX(),pos->getY()-de);
        break;
    case 'E':
    case 'e':
        pos->changePos(pos->getX()+de,pos->getY());
        break;
    default:
        pos->changePos(pos->getX()-de,pos->getY());
    }
}

bool Squab::lineOfSight(Squab s)const{
    if (pos->getX()==s.pos->getX() || pos->getY()==s.pos->getY())
        return true;
    else
        return false;
}

Squab* Squab::clone() const{
return new Squab(*this);
}

Squab::~Squab() {
    qDebug() << "In destructor";
    delete pos;
}

Squab::Squab(const Squab & s){
    qDebug() << "In copy constructor";
    new Position(*s.pos);
}

Squab& Squab::operator=(const Squab& s){
    qDebug() << "In copy assignment operator";
    if (this != &s)
            *pos = *s.pos;
    return *this;
}

