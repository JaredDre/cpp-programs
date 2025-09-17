#include "Position.h"

Position::Position(int x, int y){
    x = x;
    y = y;
}

void Position::changePos(int x, int y){
    this->x = x;
    this->y = y;
}

int Position::getX()const{
 return x;
}

int Position::getY()const{
 return y;
}
