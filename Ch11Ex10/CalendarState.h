/*  CalendarState

This class is an application state which holds the logic for Chapter 11 Programming Exercise #10.
Implements IApplicationState - see that for comments on each of the override methods.
*/

#pragma once

#include "IApplicationState.h"
#include "StateManager.h"
#include "CalendarType.h"

class CalendarState : public IApplicationState {
	StateManager& _manager;
	CalendarType* _myCalendar;
public:
	CalendarState(StateManager& manager) : _manager(manager) , _myCalendar(nullptr){}
	void activate() override;
	void deactivate() override;
	void processUserInput(int userMenuSelection) override;
	void render() override;

};
