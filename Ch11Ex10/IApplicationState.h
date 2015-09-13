/*
Interface implemented by all Application states, and used in StateManager 
to allow swapping between various different types of application states - has 4 pure virtual methods(excluding destructor):
	-activate() - called at beginning of state activation
	-deactivate() - called right before state is deleted and swapped with another
	-processUserInput() - called during StateManager.run() - processes the input by the user for the current state
	-render() - handles displaying the state's menu, or anything else that should be rendered to the screen
*/
#pragma once

class IApplicationState {
public:
	virtual ~IApplicationState() = 0;

	//to be run before state starts
	virtual void activate() = 0;

	//to be run before state is deleted and swapped
	virtual void deactivate() = 0;

	//to handle user input for the state
	virtual void processUserInput(int userInput) = 0;

	//to handle menu rendering
	virtual void render() = 0;
};
inline IApplicationState::~IApplicationState() {
	
}

