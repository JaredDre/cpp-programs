#ifndef SENTENCEPROCESSOR_H
#define SENTENCEPROCESSOR_H
#include <QString>

class SentenceProcessor {
private:
    QString s;
public:
    SentenceProcessor();

    int getWordNumber(QString sentence);
    int getVowelNumber(QString sentence);
    bool isReversible(QString sentence);
    QString wordsReversed(QString sentence);
    QString formatSentence(QString sentence);
};

#endif // SENTENCEPROCESSOR_H
