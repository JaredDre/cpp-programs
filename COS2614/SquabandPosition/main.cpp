#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include <QApplication>

#include "Squab.h"
#include "Position.h"


void display(Squab * s)
{
   QMessageBox noc;
   noc.setText("The score is: " + QString::number(s->getScore()) + " and the position is(x;y): "
                + QString::number(s->getPos().getX()) + ';' + QString::number(s->getPos().getY())) ;
            noc.exec();
}

int main (int argc,char *argv[]){
    QApplication a(argc, argv);
    int xC, yC, dist=0;
    xC=yC=0;
    xC = QInputDialog::getInt(0, "Enter", "Please enter the x-coordinate:", 1);
    yC = QInputDialog::getInt(0, "Enter", "Please enter the y-coordinate:", 1);
    Squab * s1 = new Squab(xC,yC);
    s1->incScore();
    display(s1);

    xC=yC=0;
    xC = QInputDialog::getInt(0, "Enter", "Please enter the x-coordinate:", 1);
    yC = QInputDialog::getInt(0, "Enter", "Please enter the y-coordinate:", 1);
    Squab * s2 = new Squab(xC,yC);;//Squab to check lineOfSight
    bool line;
    line=s1->lineOfSight(*s2);
    if (line)
        QMessageBox::information(0,"True","The new squab is in the line of sight of the current squab");
    else
        QMessageBox::information(0,"False","The new squab is not in the line of sight of the current squab");

    dist = QInputDialog::getInt(0, "Enter distance", "Please enter the distance to go towards east:", 1);
    s1->move('E',dist);

    xC=yC=0;
    //The clone squabs
    Squab* s3 = s1->clone();
    Squab* s4 = s1->clone();
    QMessageBox::information(0,"Coordinates","Coordinates of clone 1");
    display(s3);
    QMessageBox::information(0,"Coordinates","Coordinates of clone 2");
    display(s4);

    delete s1;

    return EXIT_SUCCESS;
}
