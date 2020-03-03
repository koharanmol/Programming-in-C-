// Final Project Milestone 1
//
// Version 1.0
// Date 2018/NOV/2
// Author Anmol Singh
// Description first milestone and this is the implementation file for Date class
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include <iostream>
#include<iomanip>
#include "Date.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace aid {
	// constructor that sets the values to safe empty state.
	//
	Date::Date() {
		year = 0;
		day = 0;
		month = 0;
		comparator = 0;
		errorstate = NO_ERROR;
	}
	// this constructor sets the valied values
	//
	Date::Date(int YEAR, int MONTH, int DAY) {
		if (YEAR >= min_year && YEAR <= max_year && MONTH >= 1 && MONTH <= 12 && DAY <= mdays(MONTH, YEAR)) {
			year = YEAR;
			month = MONTH;
			day = DAY;
			errorstate = NO_ERROR;
			comparator = year*372 + month*31 + day;
		}
		else{
			*this = Date();
		}
	}
	//this is the destructor
	//
	Date::~Date() {
	}
	// it sets errorcode
	//
	void Date::errCode(int errorCode){
     		errorstate = errorCode;
    	}
	//it returns error statement 
	//
	int Date::errCode() const{
      		return errorstate;
    	}
	//its returning the error state of noerror
	//
	bool Date::bad() const{
		return errorstate == NO_ERROR;
	}
	//check wheather both values are equal
	//
	bool Date::operator==(const Date& rhs) const{
		bool day = this->day == rhs.day;
		bool month = this->month == rhs.month;
		bool year = this->year == rhs.year;
		return (day && month && year);
     }
	//check wheather both values are not equal
	//
	bool Date::operator!=(const Date& rhs) const

	{
		return !(*this == rhs);

	}
	//check wheather its greter than the given numbers
	//
	bool Date::operator<(const Date& rhs) const{
		bool NOTYear = this->year < rhs.year;
		bool NOTMonth = this->month < rhs.month;
		bool NOTDay = this->day < rhs.day;
		if (NOTYear){
			return true;
		}
		else if (NOTMonth) {
			return true;
		}

		else if (NOTDay) {
           		return true;
         	}
        	else{
			return false;
         	}
	}	
	//check wheather its lesser than the given numbers
	//
	bool Date::operator>(const Date& rhs) const{
		return !(*this < rhs);
	}
	bool Date::operator<=(const Date& rhs) const{
		return *this < rhs || *this == rhs;
	}
	bool Date::operator>=(const Date& rhs) const{
		return *this > rhs || *this == rhs;
    }
	// number of days in month mon and year year
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	//shows the error state
	//

	istream& Date::read(istream & istr){
		
		errCode(NO_ERROR);
		char c;
		istr >> year >> c >> month >> c >> day;;
		if (istr.fail()) {
			*this = Date();
			errCode(CIN_FAILED);
		}
		if (year < min_year || year > max_year) {
                       *this = Date();
			errCode(YEAR_ERROR);
			istr.clear();			
		}
		else if (month < 1 || month > 12) {
                       *this = Date();
			errCode(MON_ERROR);
			istr.clear();
		}
		else if (day < 1 || day > mdays(month, year)) {
                     *this = Date();
			errCode(DAY_ERROR);
			istr.clear();			
		}
		else if (year*372 + month*31 + day < min_date){
                      	*this = Date();
			errCode(PAST_ERROR);
			istr.clear();			
		}
		return istr;
	}
	//funtion for setting year format
	//
	ostream & Date::write(ostream & ostr) const {
		ostr << year << "/";

		if (month >= 0 && month < 10)
			ostr << "0" << month << "/";
		else
			ostr << month << "/";

		if (day >= 0 && day < 10)
			ostr << "0" << day;
		else
			ostr << day;

		return ostr;
	}
	//its an iostrem funtion for >>
	//
	std::istream& operator>>(std::istream& istr, Date& D){
		return D.read(istr);
	}

	//its an iostrem funtion for >>
    //
	std::ostream& operator<<(std::ostream& ostr, const Date& D){
		return D.write(ostr);
    }
}




