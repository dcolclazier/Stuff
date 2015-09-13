#include "dateType.h"
#include <iostream>
#include "Input.h"

using std::cout;

/*	dateType::setDate - returns VOID
	Params:
		month - holds the month entered by the user
		day - holds the day entered by the user
		year - holds the year entered by the user
	Purpose:
		Validates the information entered by the user before assigning the fields of the class.
*/
void dateType::setDate(int month, int day, int year) {

	//if we got an invalid year, deal with it... in fact, keep dealing with it until we get a valid year.
	if(year < 1500 || year > 4000) do {
		year = Input::get_valid<int>("Enter a year between 1600 a.d. and 4000 a.d. --> ");
	} while (year <  1500 || year > 4000);

	//validate the month the same way we did the year.
	if(month > 12 || month < 1) do {
		month = Input::get_valid<int>("Enter a valid month (1 for Jan, 12 for Dec) --> ");
	} while (month > 12 || month < 1);

	//Make a note if we found a leap year, and figure out the valid days for the entered month
	auto was_leap_year = isLeapYear(year);
	auto valid_days = 31 - (month == 2 ? 3 - (was_leap_year ? 1 : 0) : (month - 1) % 7 % 2);

	//validate the day the same way we did the year - I'm totally going to abstract this somehow...
	if (day > valid_days || day < 1) do {
		cout << "\nThat month only had " << valid_days << " days in it - try again.\n";
		day = Input::get_valid<int>("Enter the day of the month --> ");
	} while (day > valid_days || day < 1);

	//assign our validated data to our private fields
	_dMonth = month;
	_dDay = day;
	_dYear = year;
	_daysInMonth = valid_days;
}


//if the year is divisible by four:
//     if it isn't divisible by 100, Go Bakula!
//     if it is divisble by 400, Go Bakula!
bool dateType::isLeapYear(int year) const {
	return year % 4 == 0 && !(year % 100 == 0) || year % 400 == 0;
}

/*	dateType::getDay - returns INT
	Params: none
	Purpose: returns the day portion of this dateType.
*/
int dateType::getDay() const {
	return _dDay;
}

/*	dateType::getMonth - returns INT
	Params: none
	Purpose: returns the month portion of this dateType.
*/
int dateType::getMonth() const {
	return _dMonth;
}

/*	dateType::getYear - returns INT
	Params: none
	Purpose: returns the year portion of this dateType.
*/
int dateType::getYear() const {
	return _dYear;
}

int dateType::getDaysInMonth() const {
	return _daysInMonth;
}

/*	dateType::printDate - returns INT
	Params: none
	Purpose: Prints the date in format "mm/dd/yyyy"
*/
void dateType::printDate() const {
	cout << "\n" << _dMonth << "/" << _dDay << "/" << _dYear;
}

/*	dateType Constructor 
	Params: 
		month - int: holds a month
		day - int: holds a day
		year - int: holds a year
	Purpose:
		Used to create a dateType instance - calls setDate and passes in the information in order to 
		validate it before assigning private fields.
*/
dateType::dateType(int month, int day, int year) {

	setDate(month, day, year);
	
}
