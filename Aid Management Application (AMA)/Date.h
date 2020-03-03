// Final Project Milestone 1
//
// Version 1.0
// Date 2018/NOV/2
// Author Anmol Singh 147528178
// Description first milestone and this is the header file for Date class
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include<iostream>
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace aid {
	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int DAY_ERROR = 2;
	const int MON_ERROR = 3;
	const int YEAR_ERROR = 4;
	const int PAST_ERROR = 5;
  class Date {

	  int year, month, day, comparator, errorstate;
     int mdays(int, int)const;
	 void errCode(int errorCode);
 
  public:
	  Date();
	  ~Date();
	  Date(int, int, int);
	  bool operator==(const Date& ) const;
	  bool operator!=(const Date& ) const;
	  bool operator<(const Date& ) const;
	  bool operator>(const Date& ) const;
	  bool operator<=(const Date& ) const;
	  bool operator>=(const Date& ) const;
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
  };

  std::ostream& operator<<(std::ostream& ostr, const Date& D);
	  std::istream& operator>>(std::istream& istr, Date& D);
}
#endif