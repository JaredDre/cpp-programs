#ifndef BMICALCULATOR_H
#define BMICALCULATOR_H

class BMIcalculator
{
public:
    BMIcalculator();
    void setWeight(double aweight);
    void setHeight(double aheight);
    bool validateValue() const;
    double calcBMI() const;
private:
    double weight;
    double height;
};

#endif // BMICALCULATOR_H
