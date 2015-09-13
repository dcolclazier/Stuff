#include "ConsoleUtilities.h"
#include <iomanip>
#include <iostream>
#include "stringUtils.h"
#include <windows.h>
#include <sstream>

using std::stringstream;
using std::setfill;
using std::setw;
using std::cout;


int add2num (int num1 , int num2) {
	return num1 + num2;
}



//Takes a list of formatted lines of text and displays them with a border of asterisks.
void ConsoleUtilities::render_lines(vector<string> lines, bool pause, int lineLength) {
	//draw the top border
	cout << setfill('*') << setw(lineLength + 5) << "\n";
	//output each line, with a * around the edge
	for each (auto line in lines) {
		cout << "* " + line + " *\n";
	}

	//output our two bottom lines - a continue message if we're pausing, and the bottom border
	if (pause) {
		cout << "*" << setfill(' ') << setw(lineLength + 2) << "" << "*\n"
			<< "* Press <Enter> to continue..." << setfill(' ') << setw(lineLength - 25) << "*\n"
			<< setfill('*') << setw(lineLength + 5) << "\n";
		std::cin.get();
	}
	else cout << setfill('*') << setw(lineLength + 5) << "\n";

}
string ConsoleUtilities::center_alligned(string input, int inputsize, int lineLength) {
	auto size = inputsize == -1 ? input.size() : inputsize;
	auto pad = (lineLength / 2) - size / 2;
	std::stringstream ss;
	ss << setfill(' ') << setw(pad) << "";
	ss << input;

	return ss.str();
}
//Clears the console window
void ConsoleUtilities::cls() {
	COORD pos = { 0,0 };
	auto output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;
	GetConsoleScreenBufferInfo(output, &screen);
	FillConsoleOutputCharacterA(output, ' ', screen.dwSize.X * screen.dwSize.Y, {0,0}, &written );
	SetConsoleCursorPosition(output, pos);
}

//Displays a message box with accurate word-wrapping onto the screen - includes a message
//telling the user to press Enter to continue if the pause flag is enabled.
void ConsoleUtilities::msg_box(const string& text, bool pause, int lineLength) {

	//get our word-wrapped lines
	vector<string> lines = StringUtils::wordWrap(text, lineLength);
	render_lines(lines, pause, lineLength);
}

//Displays a list of items, stored in listItems, after padding them to the correct length
//for the text-box
void ConsoleUtilities::list_box(vector<string> listItems, bool pause, int lineLength) {
	
	vector<string> newList;
	for each (auto item in listItems) {
		newList.push_back(StringUtils::padString(item, lineLength));
	}
	render_lines(newList, pause, lineLength);

}