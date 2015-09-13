#pragma once
#include "dateType.h"
#include <string>


//child class of dateType - allows the date to be printed in format "Month ####"
class extDateType : public dateType{
public:
	std::string printMonthAndYear();
	extDateType(int month, int year) : dateType(month, 1, year) {}
	
private:
	std::string _monthString;
};
