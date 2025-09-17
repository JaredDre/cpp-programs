#ifndef SQUAB_H
#define SQUAB_H
#include <QString>
#include "Position.h"

class Squab{
private:
    int score;
    Position * pos;
public:
    Squab(int x, int y);
    int getScore() const;
    void incScore();
    Position getPos() const;
    void move(char dn, int de);
    bool lineOfSight(Squab s) const;
    Squab* clone() const;
    ~Squab();
    Squab(const Squab & s);
    Squab& operator=(const Squab& s);
};


#endif
