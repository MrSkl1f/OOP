#include "elevator.h"

Elevator::Elevator()
{
    QObject::connect(&elevatorController, SIGNAL(setNewFloor(int)), &elevatorCabin, SLOT(cabinSetNewFloor(int)));
    QObject::connect(&elevatorCabin, SIGNAL(crossingTheFloor(int, direction)), &elevatorController, SLOT(passedFloor(int)));
    QObject::connect(&elevatorCabin, SIGNAL(cabin_stopped(int)), &elevatorController, SLOT(achievedFloor(int)));
}

void Elevator::addNewCall(int floor)
{
    elevatorController.set_new_target(floor);
}

void Elevator::setTextEdit(QTextEdit *newText)
{
    elevatorController.setText(newText);
    elevatorCabin.setText(newText);
}

void Elevator::setLabels(QLabel *doorsLabel, QLabel *cabinLabel, QLabel *floorLabel)
{
    elevatorCabin.setStateLabels(doorsLabel, cabinLabel);
    elevatorController.setFloorLabel(floorLabel);
}
