#include "Date.h"

Date::Date(int day, int month, int year)
{
    // TODO: Check the date
    this->day = day;
    this->month = month;
    this->year = year;
}
Date::~Date()
{

}


int Date::currentDaysInYear()
{
    int days = day;
    for(int i=1; i<month; i++)
    {
        days += daysInMonth(i, year);
    }
    return days;
}

bool Date::isLeap(int year)
{
    if (year%4==0 && year%100!=0)
        return true;
    if (year%400 == 0)
        return true;
    return false;
}

int Date::daysInMonth(int month, int year)
{
    switch(month)
    {
    // 1,3,5,7,8,10,12 => 31 days
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    // 2 => 28 || 29
    case 2:
        // Kiem tra nam nhuan
        if (isLeap(year))
            return 29;
        // Khi khong phai nam nhuan
        return 28;
    default:
        return 30;
    }

}



bool Date::operator<(const Date& dt)
{
    if (this->year < dt.year)
        return true;
    if (this->month < dt.month)
        return true;
    if (this->day < dt.day)
        return true;
    return false;
}

bool Date::operator>(const Date& dt)
{
    if (this->year > dt.year)
        return true;
    if (this->month > dt.month)
        return true;
    if (this->day > dt.day)
        return true;
    return false;
}

bool Date::operator==(const Date& dt)
{
    if (this->year != dt.year)
        return false;
    if (this->month != dt.month)
        return false;
    if (this->day != dt.day)
        return false;
    return true;
}

bool Date::operator!=(const Date& dt)
{
    if (this->year != dt.year)
        return true;
    if (this->month != dt.month)
        return true;
    if (this->day != dt.day)
        return true;
    return false;
}

int Date::operator-(const Date& dt)
{
    Date dt1 = *this;
    Date dt2 = dt;
    bool isNagitive = false;
    if (dt1 < dt2)
    {
        swap(dt1, dt2);
        isNagitive = true;
    }

    // Get days
    int days = 0;
    for(int i=dt2.year; i<dt1.year; i++)
    {
        days += daysInYear(i);
    }
    days = days - dt1.currentDaysInYear() + dt2.currentDaysInYear();
    if (isNagitive)
        days = -days;
    return days;
}




int Date::daysInYear(int year)
{
    if (isLeap(year))
        return 366;
    return 365;
}

bool Date::isValidDate(Date dt)
{
    return isValidDate(dt.day, dt.month, dt.year);
}


bool Date::isValidDate(int day, int month, int year)
{
    // check year
    if (year < 1)
        return false;
    // check month
    if (month < 1 || month > 12)
        return false;
    // check day
    if (day < 1 || day > daysInMonth(month, year))
        return false;
    // Ok
    return true;

}


ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.day << "-" << dt.month << "-" << dt.year;
    return os;
}
istream& operator>>(istream& is, Date& dt)
{
    is >> dt.day >> dt.month >> dt.year;
    return is;
}
ofstream& operator<<(ofstream& fo, const Date& dt)
{
    fo << dt.day << " " << dt.month << " " << dt.year;
    return fo;
}
ifstream& operator>>(ifstream& fi, Date& dt)
{
    fi >> dt.day >> dt.month >> dt.year;
    return fi;
}

Date Date::defaultDate;
