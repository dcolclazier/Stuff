#include "StateManager.h"
#include "Input.h"

//Handles moving the appliction from one state to another - calls the deactivate() method
// before deleting the current state, then sets the state to the new state before activating it
void StateManager::switch_state(IApplicationState* newState) {
	if (_current_appstate != nullptr)
		_current_appstate->deactivate();
	delete _current_appstate;

	_current_appstate = newState;
	if (newState) _current_appstate->activate();
}

//Core loop of state machine - calls the render() method on the current state, pauses to get input
//from the user(during get_valid<int>) and then runs the processUserInput() method on the current 
//state, passing in the validated user input.
void StateManager::run() {
	while (!_exitFlag) {
		_current_appstate->render();
		auto userInput = Input::get_valid<int>("Enter choice -->");
		_current_appstate->processUserInput(userInput);
		
	} 
}
