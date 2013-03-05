#ifndef DATETIME_H
#define DATETIME_H
#include "QtCore"
#include "iostream"
#include "string.h"

class DateTime
{
    QDate Date;
    QTime Time;
public:
    DateTime();
    DateTime(int);
    DateTime(QDate);
    DateTime(QTime);
    DateTime(QDate, QTime);
    qint64 getValueInSecs();
    friend DateTime operator + (const DateTime&, const DateTime&);
    friend DateTime operator ++ (DateTime&); //Prefix
    friend DateTime operator ++ (DateTime&, int); //Postfix
    friend DateTime operator += (DateTime&, int);
    friend std::ostream& operator <<(std::ostream&,const DateTime&);
    int operator -(const DateTime&);
    bool operator >(const DateTime&);
    bool operator >=(const DateTime&);
    bool operator <(const DateTime&);
    bool operator <=(const DateTime&);
    bool operator ==(const DateTime&);
    bool operator !=(const DateTime&);
    QString toString();
};

#endif // DATETIME_H
