#include "CalendarType.h"
#include "ConsoleUtilities.h"
#include <iomanip>
#include <sstream>

using std::stringstream;
//constructor initializes our private fields
CalendarType::CalendarType(int month, int year) : _monthAndYear(extDateType(month,year)) {
	_firstDayOfMonth = firstDayOfMonth();
}

//sets the date, assuming the first day of the month
void CalendarType::setDate(int month, int year) {
	_monthAndYear.setDate(month, 1, year);
}

//return this calendar's month
int CalendarType::getMonth() {
	return _monthAndYear.getMonth();
}

//returns this calendar's year
int CalendarType::getYear() {
	return _monthAndYear.getYear();
}

//returns what should be at the top of the calendar - in this case, the month and year in question
string CalendarType::getTitle() {
	return _monthAndYear.printMonthAndYear();
}


//returns the column titles - currently just the names of the week in 3-letter abbreviations
string CalendarType::getDayColumns() {
	stringstream days;
	days << std::setw(6) << "Sun"
		<< std::setw(6) << "Mon"
		<< std::setw(6) << "Tue"
		<< std::setw(6) << "Wed"
		<< std::setw(6) << "Thu"
		<< std::setw(6) << "Fri"
		<< std::setw(6) << "Sat";
	return days.str();
}

void CalendarType::printCalendar() {
	

	//our list of lines - what will be sent to the list_box for rendering - go ahead and add the title and column headers
	vector<string> calendarLines = {
		
		ConsoleUtilities::center_alligned(getTitle()),
		ConsoleUtilities::center_alligned(getDayColumns(),40)
	};

	//some useful variables for reference
	auto columnCount = 7;
	auto columnsToSkip = _firstDayOfMonth;
	auto currentColumn = 1;
	stringstream currentRow;
	
	//pad the first row of days so the 1st day appears in the correct column
	for (auto i = 0; i < columnsToSkip; i++) {
		
		currentRow << std::setw(6) << " ";
		currentColumn++;
	}

	//after we pad, if we end up on a column that's invalid, reset the current row
	if (currentColumn > (int)Saturday) {
		
		currentColumn = Sunday;
		currentRow.str("");
	}

	//for each day in this month, put the number of the day in the correct column
	for (auto day = 1; day <= _monthAndYear.getDaysInMonth(); day++) {

		//print the day, and move to the next column
		currentRow << std::setw(6) << day;
		currentColumn++;
		
		//if we past the last column, reset the column, add the row to our list of rows, and reset the row buffer
		if(currentColumn > columnCount) {
		
			currentColumn = Sunday;
			calendarLines.push_back(ConsoleUtilities::center_alligned(currentRow.str(),40));
			currentRow.str("");
		}
	}

	//don't forget to add the last row!
	calendarLines.push_back(ConsoleUtilities::center_alligned(currentRow.str(), 40));

	//add an empty line for spacing in the listbox
	calendarLines.push_back(" ");

	//send the completed calendar to the listbox for rendering to the console
	ConsoleUtilities::list_box(calendarLines, false);
}

CalendarType::dayType CalendarType::firstDayOfMonth() {

	auto currentFirstDay = 1; //start at monday


	//loop through every year
	for (auto year = 1500; year <= getYear(); year++) {

		//loop through each month in the year
		for (auto month = (int)January; month <= (int)December; month++) {
			//if this month is the same as the calendar, get out of here... we already have the first day
			if (getYear() == year && month == getMonth()) break;
			
			//create a temporary date for the day and get the number of days in the month
			auto date = dateType(month, 1, year);
			auto daysInMonth = date.getDaysInMonth();
			
			//increment currentFirstDay by the appropriate amount to account for week cycles
			currentFirstDay += daysInMonth % 7;

			//if we overlapped (went past sunday) cycle the week one last time
			if (currentFirstDay > 7) currentFirstDay %= 7; 
		}
	}
	//return the first day of the month
	return static_cast<dayType>(currentFirstDay);

}

//default constructor sets date to 1/1/1500
CalendarType::CalendarType() : _monthAndYear(extDateType(1,1500)){
	
	_firstDayOfMonth = Monday;
}