#include "StateManager.h"
#include "MainMenuState.h"
#include "ConsoleUtilities.h"


int main() {
	
	ConsoleUtilities::msg_box("This is David Colclazier's submission for Program 1: Chapter 11, Ex. 10", true);

	StateManager stateManager;
	stateManager.switch_state(new MainMenuState(stateManager));
	stateManager.run();

	ConsoleUtilities::msg_box("Have a great day!", true);

	return 0;

}
