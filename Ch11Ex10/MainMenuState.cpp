#include "MainMenuState.h"
#include "StateManager.h"
#include "ConsoleUtilities.h"
#include <vector>
#include <string>
#include "CalendarState.h"

using std::string;
using std::vector;
//Runs before state starts - clears the console window.
void MainMenuState::activate() {
	
	ConsoleUtilities::cls();
}

//Runs before state is swapped with another and deleted
void MainMenuState::deactivate() {
	
	
}

//This method's parameter holds the input the user chose from the menu.
void MainMenuState::processUserInput(int userInput) {
	
	switch(userInput) {
	case 0: //exit
		_manager.quit();
		break;
	case 1: //run pool app
		_manager.switch_state(new CalendarState(_manager));
		break;
	
	default:
		break;
	}
}

//This method is called by the State manager, and is the default method for any state.
//This stat's render simply writes a main menu to the screen in a list_box.
void MainMenuState::render() {

	ConsoleUtilities::cls();
	ConsoleUtilities::list_box(vector<string>{
				"[1] - Run Calendar App ",
				"[0] - Exit"}, false);

}

