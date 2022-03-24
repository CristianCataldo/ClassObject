//Date.cpp
//Definizione member function
#include <iostream>
#include <string>
#include <array>

const std::array<int, 13> Date::days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int dd, int mm, int yy){
    setDate(dd, mm, yy);
}
 
void Date::setDate(int dd, int mm, int yy){
    if (mm >= 1 && mm <= 12){
        month = mm;
    }
    year = yy;
    if (((month == 2) && leapyear(year) && dd >= 1 && dd <= 29) || (dd >= 1 && dd <= days[month])){
        day = dd;
    }
}


bool Date::operator<(const Date &dt) const{
    if (year < dt.year)
        return true;
    else if (year == dt.year && month < dt.month)
        return true;
    else if (year == dt.year && month == dt.month && day < dt.day)
        return true;
    return false;
}


Date operator+(int numday, const Date &dt){
    Date newdate = dt;
    for (int i = 1; i <= numday; i++){
        newdate.helpIncrement();
    }
    return newdate;
}


Date operator+(const Date &dt, int numday){
    Date newdate = dt;
    for (int i = 1; i <= numday; i++){
        newdate.helpIncrement();
    }
    return newdate;
}


Date &Date::operator++(){
    helpIncrement();
    return *this;
}


Date Date::operator++(int){
    Date temp{*this};
    helpIncrement();
    return temp;
}


Date &Date::operator+=(unsigned int numday){
    for (unsigned int i = 1; i <= numday; i++){
        helpIncrement();
    }
    return *this;
}


bool Date::leapyear(int yy){
    return ((yy % 400 == 0) || (yy % 100 != 0 && yy % 4 == 0));
}


bool Date::endofmonth(int testDay) const{
    if (month == 2 && leapyear(year)){
        return testDay == 29;
    }
    else{
        return testDay == days[month];
    }
}




void Date::helpIncrement(){
    if (!endofmonth(day)){
        ++day;
    }
    else{
        if (month < 12){
            ++month;
            day = 1;
        }
        else{
            ++year;
            day = 1;
            month = 1;
        }
    }
}


std::ostream &operator<<(std::ostream &output, const Date &dt){
    static std::string monthName[13]{"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "Dicember"};
    output << dt.day << ' ' << monthName[dt.month] << ' ' << dt.year;
    return output;
}

bool Date::operator>(Date &dt){
    if(year > dt.year)
        return true;
    if(year==dt.year && month>dt.month)
        return true;
    if(year==dt.year && month==dt.month && day>dt.day)
        return true;
    return false;
}
bool Date::operator>=(Date &dt){
    if(year >= dt.year)
        return true;
    if(year==dt.year && month >= dt.month)
        return true;
    if(year==dt.year && month==dt.month && day >= dt.day)
        return true;
    return false;
}
bool Date::operator<=(const Date& dt) const{
    if (year <= dt.year)
        return true;
    else if (year == dt.year && month <= dt.month)
        return true;
    else if (year == dt.year && month == dt.month && day <= dt.day)
        return true;
    return false;
}
bool Date::operator!=(const Date& dt) const{
    if(year!=dt.year || month!=dt.month || day!=dt.day)
        return true;
    return false;
}
bool Date::operator==(const Date& dt) const{
    if(year==dt.year && month==dt.month && day==dt.day)
        return true;
    return false;
}

void Date::helpDecrement(){
    if(day>1){
        day--;
    }
    else{
        if (month > 1 && month!=3){
            --month;
            day = days[month];
        }
        else if(month==1){
            --year;
            day = days[month];
            month = 12;
        }
        else if(month==3 && leapyear(year)){
            day=29;
            month=2;
        }
        else if(month==3 && !leapyear(year)){
            --month;
            day = days[month];
        }
    }
}

Date operator-(int numday,const Date& dt){
    Date newdate = dt;
    for (int i = 1; i <= numday; i++){
        newdate.helpDecrement();
    }
    return newdate;
}
Date operator-(const Date& dt, int numday){
    Date newdate = dt;
    for (int i = 1; i <= numday; i++){
        newdate.helpDecrement();
    }
    return newdate;
}
