/* ConsoleUtilities.h

This class contains some static functions that allow me to cleanly display text to the console window in various ways. There are three public facing methods:
	cls() - clears the screen and places the cursor at {0, 0} 
	msg_box(text, bool, int) - displays a bordered text box containing the string, wrapped correctly to the lineLength provided.
	list_box(vector<string>, bool, int) - similiar to msg_box, but rather takes in a list of smaller strings to be - for instance, menu items!

The private method:
	render_lines() - Takes a list of formatted lines of text and displays them with a border of asterisks.
*/

#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

class ConsoleUtilities {
	static void render_lines(vector<string> lines, bool pause, int lineLength);
public:
	static void cls();
	static string center_alligned(string input, int inputsize = -1, int lineLength = 68);
	static void msg_box(const string& text, bool pause, int lineLength = 68);
	static void list_box(vector<string> listItems, bool pause, int lineLength = 68);
};
