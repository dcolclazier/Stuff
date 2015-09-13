#include "stringUtils.h"

#include <iomanip>
#include <sstream>
#include <iterator>

using std::stringstream;
using std::istream_iterator;
using std::vector;

//returns a list of lines containing words wrapped - correctly, hopefully.
vector<string> StringUtils::wordWrap(const string& str, const int lineLength) {
	//let's create a vector of all of the words we need to wrap...
	stringstream ss(str);
	istream_iterator<string> begin(ss), end;
	vector<string> words(begin, end);  //God, I love stream functionality!!
	vector<string> lines;
	
	//Now let's create a loop to handle all of these words
	string nextLine;
	auto space_avail = lineLength;

	while(words.size() > 0) {
		//take the first word out of the wordlist...
		auto nextWord = words[0];
		words.erase(words.begin());
		//update the avialable space in the current line based on the size of this word
		space_avail -= (nextWord.size() + 1);
		//if there's room left for the word, go ahead and append it.
		if(space_avail > 0) nextLine.append(nextWord + " ");
		//if not..
		else {
			//pad the current line with space to fill it out to the linelength
			padString(nextLine, lineLength);
			//add the line to our list of lines
			lines.push_back(nextLine);
			//reset both the line and the space_avail
			nextLine = "";
			space_avail = lineLength - (nextWord.size() + 1);
			//append the current word to the new line.
			nextLine.append(nextWord + " ");
		}
	}
	//pad the last line and add it to the list of lines
	padString(nextLine, lineLength);
	lines.push_back(nextLine);
	return lines;

}

//This method pads a string with white space, such that the string matches a length(passed in as parameter)
string StringUtils::padString(string& str, const int length, const char padding) {
	//if the string doesn't need padding, just return it.
	auto size = str.size();
	if (static_cast<int>(size) >= length) return str;
	
	//create a stringstream with empty spaces for however long our padding needs to be
	stringstream ss;
	ss << std::setfill(padding) << "" << std::setw(length - size) << "";

	//append the padding to the string and return it.
	str.append(ss.str());
	return str;
}
