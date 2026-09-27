#include "EventGoal.h"
#include <iostream>

EventGoal::EventGoal(float x, float y) :Event("Goal", x, y)
{
}

void EventGoal::Execute()
{
    Event::Execute();
    std::cout << "Goal Event!!" << std::endl;
}
