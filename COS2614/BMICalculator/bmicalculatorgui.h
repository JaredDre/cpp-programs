#ifndef BMICALCULATORGUI_H
#define BMICALCULATORGUI_H

#include <QLineEdit>
#include <QDialog>
#include <QLCDNumber>
#include "bmicalculator.h"

class BMICalculatorGUI : public QDialog
{
    Q_OBJECT
public:
    BMICalculatorGUI();
private:
    QLineEdit* w;
    QLineEdit* h;
    QLCDNumber* BMIOutput;
    BMIcalculator bmi;
private slots:
    void calculateBMI();
    void clearAll();
};

#endif // BMICALCULATORGUI_H
