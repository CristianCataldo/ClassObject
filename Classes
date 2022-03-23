//Date.h
//Definizione della classe

#include<array>
#include<iostream>
#include <iostream>

using std::cout ;
using std::endl ;

#ifndef DATE_H
#define DATE_H

class Date{
    
    friend Date operator+(int , const Date&);
    friend Date operator+(const Date& , int);
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend Date operator-(int , const Date&);
    friend Date operator-(const Date& , int);
    
public: 
    
    Date(int dd=1,int mm=1, int yy=1900);
    bool endofmonth(int) const;
    void setDate(int,int,int);
    bool operator<(const Date&) const;
    Date& operator++();
    Date  operator++(int);
    Date& operator+=(unsigned int);
    static bool leapyear(int);
    void helpIncrement();
    bool operator>(Date&);
    bool operator>=(Date&);
    bool operator<=(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator==(const Date&) const;
	  unsigned int getDay(){return day;}
	  unsigned int getMonth(){return month ;}
	  unsigned int getYear(){return year ; }
    void helpDecrement();
	

private:
  
  unsigned int day;
  unsigned int month;
  unsigned int year;
  static const std::array<int,13> days;

};

#include "Date.cpp"
#endif
