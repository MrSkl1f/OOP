#include "controller.h"

ElevatorController::ElevatorController(QObject *parent) : QObject(parent)
{
    currentState = FREE;
    currentDirection = STAY;
    currentFloor = 0;

    for (int i = 0; i < COUNT_OF_FLOORS; i++)
        floorCalls[i] = false;

    QObject::connect(this, SIGNAL(setNewTask(int)), this, SLOT(gotNewTask(int)));
}

void ElevatorController::setFloorLabel(QLabel *currentLabel)
{
    currentFloorLabel = currentLabel;
}

void ElevatorController::setFloor(int floor)
{
    currentFloorLabel->setText(QString::number(floor));
}

void ElevatorController::setText(QTextEdit *newText)
{
    currentText = newText;
}

void ElevatorController::setNewFloor(int floor)
{
    emit setNewTask(floor);
}

void ElevatorController::gotNewTask(int floor)
{
    floorCalls[floor - 1] = true;
    if (currentState == FREE)
    {
        currentState = BUSY;
        nextFloor(floor);
        emit sendNewFloor(floor);
    }
}

void ElevatorController::achievedFloor(int floor)
{
    currentState = FREE;
    currentFloor = floor;
    currentDirection = STAY;
    floorCalls[floor - 1] = false;
    if (nextFloor(floor))
        setNewFloor(floor);
    else
        setFloor(floor);
}

void ElevatorController::passedFloor(int floor)
{
    setFloor(floor);
    currentText->append("Лифт преодолел " + QString::number(floor));
}


bool ElevatorController::nextFloor(int &floor)
{
    int directionStep = 1;
    if (currentDirection == DOWN)
        directionStep = -1;
    for (int i = currentFloor; i <= COUNT_OF_FLOORS && i > 0; i += directionStep)
    {
        if (floorCalls[i - 1])
        {
            floor = i;
            return true;
        }
    }
    directionStep = -directionStep;
    for (int i = currentFloor; i <= COUNT_OF_FLOORS && i > 0; i+= directionStep)
    {
        if (floorCalls[i - 1])
        {
            floor = i;
            return true;
        }
    }
    return false;
}
