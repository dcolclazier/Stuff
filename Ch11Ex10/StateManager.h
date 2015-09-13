#pragma once
#include "IApplicationState.h"
/*
This class is responsible for maintaining and switching between different 
application states. It keeps track of the current state, and has 3 public facing methods:
	switch_state() - seamlessly changes states from the current state to newState
	run() - contains main state machine loop
	quit() - may be called by any of the states to trigger the exitFlag, causing the application to terminate
*/
class StateManager {

public:
	void switch_state(IApplicationState* newState);
	void run();
	void quit() { _exitFlag = true;	}
	
private:
	IApplicationState* _current_appstate = nullptr;
	bool _exitFlag = false;
};

