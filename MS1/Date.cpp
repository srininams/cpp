// Final Project Milestone 1
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2021/10/29		       Preliminary release
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds
{
   bool Date::validate()
   {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1)
      {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12)
      {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays())
      {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays() const
   {
      int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear() const
   {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }
   void Date::setToToday()
   {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1() const
   { // Rata Die day since 0001/01/01
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3)
      {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() : m_CUR_YEAR(systemYear())
   {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear())
   {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char *Date::dateStatus() const
   {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear() const
   {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode)
   {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode() const
   {
      return m_ErrorCode;
   }
   bool Date::bad() const
   {
      return m_ErrorCode != 0;
   }

   int Date::year() const // returns the year
   {
      return m_year;
   }
   int Date::month() const // returns the month
   {
      return m_mon;
   }
   int Date::day() const // returns the day
   {
      return m_day;
   }

   ostream &operator<<(ostream &os, const Date &RO)
   {
      return RO.write(os);
   }
   istream &operator>>(istream &is, Date &RO)
   {
      return RO.read(is);
   }

   std::istream& Date::read(std::istream &is)
   {
      char ch;

      is >> m_year >> ch >> m_mon >> ch >> m_day;
      if (is.fail())
      {
         errCode(CIN_FAILED);
         is.clear();
      }
      else
      {
         validate();
      }
      is.ignore();
      return is;
   }

   std::ostream& Date::write(std::ostream& os ) const    
   {
      if (bad())
      {
         os << dateStatus();
      }
      else
      {
         os << setfill('0') << setw(4) << m_year << "/" << setw(2) << m_mon << "/" << setw(2) << m_day;
      }
      return os;
   }

   bool Date::operator==(const Date dt2)
   {
      return year() == dt2.year() && month() == dt2.month() && day() == dt2.day();
   }
   bool Date::operator!=(const Date dt1)
   {
      return !(*this == dt1);
   }
   bool Date::operator>=(const Date dt2)
   {
      return year() > dt2.year() || (year() == dt2.year() && month() > dt2.month()) || (year() == dt2.year() && month() == dt2.month() && day() >= dt2.day());
   }
   bool Date::operator<=(const Date dt2)
   {
      return year() < dt2.year() || (year() == dt2.year() && month() < dt2.month()) || (year() == dt2.year() && month() == dt2.month() && day() <= dt2.day());
   }
   bool Date::operator<(const Date dt2)
   {
      return year() < dt2.year() || (year() == dt2.year() && month() < dt2.month()) || (year() == dt2.year() && month() == dt2.month() && day() < dt2.day());
   }
   bool Date::operator>(const Date dt2)
   {
      return year() > dt2.year() || (year() == dt2.year() && month() > dt2.month()) || (year() == dt2.year() && month() == dt2.month() && day() > dt2.day());
   }

   int Date::operator-(const Date dt1)
   {
      return daysSince0001_1_1() - dt1.daysSince0001_1_1();
   }
   bool Date::operator!()
   {
      return validate();
   }

}
