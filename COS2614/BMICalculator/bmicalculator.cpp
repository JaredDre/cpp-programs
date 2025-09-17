#include <QtGlobal>
#include "bmicalculator.h"

BMIcalculator::BMIcalculator(): weight(0),height(0)
{
}

void BMIcalculator::setWeight(double aweight){
    weight=aweight;
}

void BMIcalculator::setHeight(double aheight){
    height=aheight;
}

bool BMIcalculator::validateValue() const{
    if (weight==0 && height==0)
        return false;
    return true;
}

double BMIcalculator::calcBMI() const{
    double BMIval=weight/(height*height);
    return BMIval;
}
