#include "SentenceProcessor.h"
#include <QVector>

SentenceProcessor::SentenceProcessor(){
s=" ";
}

int SentenceProcessor::getWordNumber(QString sentence){
int n = sentence.length();
QChar str[n+1];
int numWords=0;
if (n>0)
    numWords++;
for(int i=0; i != n; i++){
str[i]=sentence[i];
}
for(int i=0; str[i] != '\0'; i++)
{
      if (str[i]==' ')
        numWords++;
}//for loop
return (numWords);
}

int SentenceProcessor::getVowelNumber(QString sentence){
int n = sentence.length();
QChar str[n+1];
int numVowels=0;
numVowels=0;

for(int i=0; i != n; i++){
str[i]=sentence[i];
}
for(int i=0; str[i] != '\0'; i++)
{
    if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
        str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
            numVowels++;

}
return numVowels;
}

bool SentenceProcessor::isReversible(QString sentence){
QVector<QString> vSentence;
QString str = "";
bool bSen=true;

for (int i = 0; i < sentence.length(); i++)
{
 if (sentence[i] == ' ')
    {
        vSentence.push_back(str);
        str = "";
    }//if
        else
        str += sentence[i];
}//for
vSentence.push_back(str);
int n=0;
int size=vSentence.size()-1;

for (int i=size;i >= 0;i--)
{
    if (vSentence[i] != vSentence[n])
        bSen= false;
    n++;
}
return bSen;
}

QString SentenceProcessor::wordsReversed(QString sentence){

QVector<QString> temp;//vector to temporary store word
QString rSentence, str = "";

int pos=sentence.length();
QChar s=sentence[pos-1];
if (s=='.')
sentence.remove(pos-1,1);

for (int i = 0; i < sentence.length(); i++)
{

    // Check if we encounter space push word(str) to vector
    // and make str NULL
    if (sentence[i] == ' ')
    {
        temp.push_back(str);
        str = "";
    }//if
    // add character to str to form current word
    else
        str += sentence[i];
}//for
// Last word remaining,add it to vector
temp.push_back(str);

// Now add from last to first in vector to variable

int i;
for (i = temp.size() - 1; i > 0; i--)
    rSentence = rSentence + temp[i] + " ";
    // Last word remaining,print it
rSentence = rSentence + temp[0];
return (rSentence);
}

QString SentenceProcessor::formatSentence(QString sentence){
int pos;
QChar str,c;

c=sentence[0].toUpper();
sentence[0]=c;
pos=sentence.length();
str=sentence[pos-1];

if (str!='.')
    sentence=sentence + '.';
return sentence;
}

