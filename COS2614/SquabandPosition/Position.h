#ifndef POSITION_H
#define POSITION_H
#include <QString>


class Position{
private:
    int x;
    int y;
public:
    Position(int x, int y);
    void changePos(int x, int y);
    int getX() const;
    int getY() const;
};

#endif // COORDINATE_H
