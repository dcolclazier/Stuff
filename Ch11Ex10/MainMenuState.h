/*
This is the starting application state - the main menu. Displays an option to start the assignment-specific logic or
to exit the application. Has all of the functions required by the IApplicationState interface, and holds onto a 
reference to the StateManager for purposes of switching states.
*/

#pragma once

#include "IApplicationState.h"
#include "StateManager.h"

class MainMenuState : public IApplicationState {
public:
		
	void activate() override;
	void deactivate() override;
	void processUserInput(int userMenuChoice) override;
	void render() override;
	
	MainMenuState(StateManager& manager) :_manager(manager) {}

private:
	StateManager& _manager;
};


