#include "elevator.h"

Elevator::Elevator()
{
    QObject::connect(&elevatorController, SIGNAL(sendNewFloor(int)), &elevatorCabin, SLOT(gotNewFloor(int)));
    QObject::connect(&elevatorCabin, SIGNAL(crossingTheFloor(int)), &elevatorController, SLOT(passedFloor(int)));
    QObject::connect(&elevatorCabin, SIGNAL(cabinStopped(int)), &elevatorController, SLOT(achievedFloor(int)));
}

void Elevator::addNewCall(int floor)
{
    elevatorController.setNewFloor(floor);
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
