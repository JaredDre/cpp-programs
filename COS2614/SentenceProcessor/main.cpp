#include "SentenceProcessor.h"
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>


int tryAgain(){
    return QMessageBox::question(0, "Another sentence", "Do you want to enter another sentence? ",
                                 QMessageBox::Yes | QMessageBox::No);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int answer = 0;
    QString input;

    do{

       input = QInputDialog::getText(0, "Enter Sentence","Enter a sentence:");

        QString bSen="The sentence is not reversible";

         SentenceProcessor sen;

         if (sen.isReversible(input))
        bSen="The sentence is reversible";

         QMessageBox noc;

           QString sWord=QString::number(sen.getWordNumber(input));
           QString vWord=QString::number(sen.getVowelNumber(input));
           noc.setText("Number of words in sentence: " + sWord+ "\nNumber of vowels in sentence: " + vWord +
                       "\nIs the sentence reversible?: " + bSen+"\nThe sentence in reverse: "+
                       sen.wordsReversed(input)+ "\nThe sentence formatted: "+sen.formatSentence(input));
           noc.exec();

          answer = tryAgain();
    }while(answer == QMessageBox::Yes);//outer do loop

    return EXIT_SUCCESS;

}
