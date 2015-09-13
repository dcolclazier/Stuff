#include "Input.h"
#include "ConsoleUtilities.h"
#include "MainMenuState.h"
#include <string>
#include <vector>
#include "CalendarState.h"

using std::string;
using std::vector;

//Clears the screen, then asks the user for the minimal information needed to create a pool.
//Then creates a pool on the heap.
void CalendarState::activate() {

	ConsoleUtilities::cls();



}

//deletes the dynamic memory before returning to another state (in this case, the only
// option is the main menu)
void CalendarState::deactivate() {
	delete _myCalendar;
}

//Processes and reacts to the user input received by the user in the StateManager
//This method handles the responses for each of the 9 options listed in the render() method
//future applications should have this refactored into some sort of event system - i tend to try to avoid switch/case and repeating if
void CalendarState::processUserInput(int userInput) {
	std::stringstream ss;
	switch (userInput) {
	case 0: //Main menu
		ss << "Taking you back to the main menu...";
		_manager.switch_state(new MainMenuState(_manager));
		break;
	case 1: 
		_myCalendar = new CalendarType(Input::get_valid<int>("\nEnter the month: "), Input::get_valid<int>("\nEnter the year: "));
		_myCalendar->printCalendar();
		break;
	case 2: 
		break;
	default: //Invalid 
		ss << "Invalid choice...";
		break;
	}
	ConsoleUtilities::msg_box(ss.str(), true);
}

//lists the 7 avlid options for the user to enter to progress through the application.
void CalendarState::render() {
	ConsoleUtilities::cls();
	ConsoleUtilities::list_box(vector<string>{
		"[1] - Print a Calendar ",
		"[0] - Main Menu (WARNING - data is not                 saved.)"}, false);

}