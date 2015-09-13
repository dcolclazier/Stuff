/* Input 

	This class handles input validation of all types from user input. It contains one public facing templated method - get_valid,
	which recursively repeats itself until input of a particular type is received from the user. For example, get_valid<int> will not 
	accept "1 2" or "apple" or "1." as valid entries, will inform the user, and get new input. 
*/
#pragma once
#include <string>
#include <sstream>
#include <iostream>

using std::string;

class Input {
	/*	Input::is_valid<T> - returns BOOL
		Params:
			input - holds the raw input the user entered into the console window
			value - holds the variable of the indicated type that we're gonna try
					to convert the user input into
		Purpose:
			Uses a conversion mechanism in stringstream to attempt to convert the
			user input from a string to some type 'T' - could be int, float, or apple.
			Returns true only if the conversion was successful and if all of the user input was 
			converted.
	*/
	template <typename T>
	static bool is_valid(const string& input, T& value) {
		std::istringstream iss(input);
		iss >> std::noskipws >> value;
		return iss.eof() && !iss.fail();
	}

	/*	Input::get_raw_input() - returns STRING
		Params:
			prompt - the prompt passed as a parameter to get_valid<T>()
		Purpose:
			Simple - outputs a prompt, gets input from the user, and returns it.
	*/
	static string get_raw_input(const string& prompt) {
		string input;
		std::cout << prompt;
		getline(std::cin, input);
		return input;
	}
public:
	
	/*	Input::get_valid<T> - returns T
	Params:
		prompmt - the prompt to display to the user - should tell the user what type of data they
					should be entering.
	Purpose:
		This is the public facing Input validation function - it creates a variable of the type you
		specify, gets input from the user (outputting the prompt you specify) and either returns the validated input or recursively calls itself until validated input is received.
	*/
	template <typename T>
	static T get_valid(const string& prompt) {
		T value;
		auto input = get_raw_input(prompt);
		return is_valid<T>(input, value) ? value : get_valid<T>("Invalid entry - please try again. ->");
	}
	
};
