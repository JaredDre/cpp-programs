#include "bmicalculatorgui.h"
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QMessageBox>


BMICalculatorGUI::BMICalculatorGUI() :w(new QLineEdit()),h(new QLineEdit()),BMIOutput(new QLCDNumber()){
    QLabel* weightText=new QLabel("Enter weight in kilogram");
    QLabel* heightText=new QLabel("Enter height in meters");
    QLabel* BMIText=new QLabel("BMI");
    QPushButton* calculate=new QPushButton("Calculate");
    QPushButton* clear=new QPushButton("Clear All");
    BMIOutput->setSegmentStyle(QLCDNumber::Filled);

    QGridLayout* layout=new QGridLayout();
    layout->addWidget(weightText, 0,0);
    layout->addWidget(heightText, 1,0);
    layout->addWidget(BMIText, 3,0);
    layout->addWidget(w, 0,1);
    layout->addWidget(h, 1,1);
    layout->addWidget(calculate, 2,1);
    layout->addWidget(BMIOutput, 3,1);
    layout->addWidget(clear, 4,1);

    this->setLayout(layout);
    this->setWindowTitle("BMI Calculator");

    connect(calculate, SIGNAL(clicked()), this, SLOT(calculateBMI()));
    connect(clear, SIGNAL(clicked()), this, SLOT(clearAll()));
}

void BMICalculatorGUI::calculateBMI(){
    QString strVal;
    double weightValue=0;
    double heightValue=0;

    strVal=w->text();
    bool ok1(false);
    double d = strVal.toDouble(&ok1);
    if (ok1) {
       weightValue = d;
    }
    strVal=h->text();
    bool ok2(false);
    d = strVal.toDouble(&ok2);
    if (ok2) {
          heightValue = d;
      }
    double BMIvalue =0;

    bmi.setWeight(weightValue);
    bmi.setHeight(heightValue);

    if(!bmi.validateValue()){
        QMessageBox::information(this, "Input Error", "Weight or Height can only be a number",0,0);
    }
    else{
        BMIvalue=bmi.calcBMI();
        BMIOutput->display(BMIvalue);

    }
}
void BMICalculatorGUI::clearAll() {
    w->text()="";
    h->text()="";
    BMIOutput->display(0);
}



