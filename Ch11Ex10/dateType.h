#pragma once

/*
dateType.h - holds onto a day, month, and year, and validates the date against the correct number of days
			for the month, accounting for leap year.
*/

class dateType {
public:
	//getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	int getDaysInMonth() const;
	//prints the date in mm/dd/yyyy format
	void printDate() const;
	
	//validate the input and sets private fields
	void setDate(int month, int day, int year);
	
	//constructor
	explicit dateType(int month = 1, int day = 1, int year = 1900);

private:
	//returns true if the year parameter was a leap year.
	bool isLeapYear(int year) const;

	//private fields
	int _dMonth;
	int _dDay;
	int _dYear;
	int _daysInMonth;
};
