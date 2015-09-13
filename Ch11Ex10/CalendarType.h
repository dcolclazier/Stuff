/* CalendarType.h

This is the class required by excercise 10. It has 2 public facing methods aside from the constructor:

setDate(int month, year) - calls setDate on the extDateType, validating the date entered by the user and assigning it to our calendar - Assumes day 1 for the month
printCalendar(text, bool, int) - displays a bordered text box containing the string, wrapped correctly to the lineLength provided.
list_box(vector<string>, bool, int) - similiar to msg_box, but rather takes in a list of smaller strings to be - for instance, menu items!

The private members:

	dayType - enum for each day of the week
	dayType firstDayOfMonth() - finds the dayType for the 1st of the month
	int getMonth() returns the calendar month as an int
	int getYear() returns the calendar year as an int
	string getTitle() returns the string that should be printed at the top of the calendar
	string getDayColumns() returns the string containing the column titles (currently 3 letters for each day)
	extDateType _monthAndYear - holds the date for the calendar, namely the month and year.
	dayType _firstDayOfMonth - holds the dayType for the 1st of the month.
*/

#pragma once
#include "extDateType.h"

class CalendarType {
public:

	void setDate(int month, int year);
	void printCalendar();
	
	CalendarType(int month, int year);
private:

	enum dayType {Sunday=1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
	enum monthType {January=1, February, March, April, May, June, July, August, September, October, November, December};

	dayType firstDayOfMonth();
	CalendarType();
	int getMonth();
	int getYear();
	std::string getTitle();
	std::string getDayColumns();
	extDateType _monthAndYear;
	dayType _firstDayOfMonth;

};
