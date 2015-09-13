#include "extDateType.h"
#include  <sstream>

//prints the month and year in format "February 1680"
std::string extDateType::printMonthAndYear() {
	
	switch(getMonth()) {
	case 1: _monthString = "January"; 	break;
	case 2: _monthString = "February"; 	break;
	case 3: _monthString = "March"; 	break;
	case 4: _monthString = "April"; 	break;
	case 5: _monthString = "May"; 		break;
	case 6: _monthString = "June"; 		break;
	case 7: _monthString = "July"; 		break;
	case 8: _monthString = "August"; 	break;
	case 9: _monthString = "September"; break;
	case 10: _monthString = "October"; 	break;
	case 11: _monthString = "November"; break;
	case 12: _monthString = "December"; break;
	default: _monthString = ""; break; 	}

	std::stringstream ss;
	ss << _monthString << " " << getYear();
	return ss.str();
}