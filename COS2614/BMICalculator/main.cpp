#include "bmicalculatorgui.h"
#include "bmicalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BMICalculatorGUI bmiVal;
    bmiVal.show();

    return a.exec();
}
