#include "datetime.h"

DateTime::DateTime()
{
/*    QDateTime temp;
    temp.setTime_t(0);
    this->Date = temp.date();
    this->Time = temp.time();
*/
    this->Date = this->Date.currentDate();
    this->Time = this->Time.currentTime();
}

DateTime::DateTime(int seconds)
{
    QDateTime temp;
    temp.setTime_t(seconds);
    this->Date = temp.date();
    this->Time = temp.time();
}

DateTime::DateTime(QDate newDate, QTime newTime)
{
    this->Date = newDate;
    this->Time = newTime;
}


DateTime::DateTime(QTime newTime)
{
    this->Date = this->Date.currentDate();
    this->Time = newTime;
}

DateTime::DateTime(QDate newDate)
{
    this->Date = newDate;
    this->Time = this->Time.currentTime();
}

qint64 DateTime::getValueInSecs()
{
    QDateTime temp(this->Date, this->Time);
    return temp.toTime_t();

}

DateTime operator +(const DateTime &a, const DateTime &b)
{
    QDateTime temp;
    QDateTime left(a.Date, a.Time);
    QDateTime right(b.Date, b.Time);
    temp.setTime_t(left.toTime_t() + right.toTime_t());
    DateTime result(temp.date(), temp.time());
    return result;
}

int DateTime::operator -(const DateTime &a)
{
    QDateTime left(this->Date, this->Time);
    QDateTime right(a.Date, a.Time);
    return left.toTime_t() - right.toTime_t();
}


bool DateTime::operator >(const DateTime &b)
{
    if ((this->Date > b.Date)||((this->Time > b.Time)&&(this->Date == b.Date)))
        return true;
    else
        return false;
}

bool DateTime::operator >=(const DateTime &b)
{
    if ((this->Date > b.Date)||((this->Time >= b.Time)&&(this->Date == b.Date)))
        return true;
    else
        return false;
}

bool DateTime::operator <(const DateTime &b)
{
    if ((this->Date < b.Date)||((this->Time < b.Time)&&(this->Date == b.Date)))
        return true;
    else
        return false;

}

bool DateTime::operator <=(const DateTime &b)
{
    if ((this->Date < b.Date)||((this->Time <= b.Time)&&(this->Date == b.Date)))
        return true;
    else
        return false;

}

bool DateTime::operator ==(const DateTime &b)
{
    if ((this->Time == b.Time)&&(this->Date == b.Date))
        return true;
    else
        return false;

}

bool DateTime::operator !=(const DateTime &b)
{
    if ((this->Date != b.Date)||(this->Time != b.Time))
        return true;
    else
        return false;

}


std::ostream& operator <<(std::ostream &ostr, const DateTime &outDT)
{
    std::string date = outDT.Date.toString().toStdString();
    std::string time = outDT.Time.toString().toStdString();
    ostr<<date<<" "<<time;
    return ostr;
}

QString DateTime::toString()
{
    return Date.toString().append(" ").append(Time.toString());
}

DateTime operator ++(DateTime & left, int i)
{
    DateTime temp(1);
    left = left + temp;
    return left;
}


DateTime operator ++(DateTime & right)
{
    DateTime temp;
    temp.Date = right.Date;
    temp.Time = right.Time;
    right++;
    return temp;
}


DateTime operator +=(DateTime & left, int right)
{
    DateTime temp(right);
    left = left+temp;
    return left;
}
