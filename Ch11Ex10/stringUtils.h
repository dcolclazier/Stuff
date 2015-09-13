#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;
/*
This class holds two static methods which are used by the ConsoleUtilities classes to handle word-wrapping and length-padding
for purposes of formatting the display of text in the console window.
	wordwrap(const string&, int) - takes in a string, splits it into words, and places them into equally long lines which it returns
	padString(string&, int, const char) - pads a string parameter with extra padding until it is a particular length

*/
class StringUtils {
public:
	static vector<string> wordWrap(const string& str, int lineLength);
	static string padString(string& str, const int length, const char padding = ' ');
};
