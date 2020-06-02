#include "controller.h"

// начальное состояние контрольной панели
ElevatorController::ElevatorController(QObject *parent) : QObject(parent)
{
    currentState = FREE;
    currentDirection = STAY;
    currentFloor = 0;

    for (int i = 0; i < COUNT_OF_FLOORS; i++)
        calls[i] = false;
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

void ElevatorController::set_new_target(int floor)
{
    currentState = BUSY;
    calls[floor - 1] = true;
    nextFloor(floor);
    emit setNewFloor(floor);
}

void ElevatorController::achievedFloor(int floor)
{
    if (currentState == BUSY)
    {
        currentFloor = floor;
        currentDirection = STAY;
        calls[floor - 1] = false;

        if (nextFloor(floor))
            emit setNewFloor(floor);
        else
        {
            setFloor(floor);
            currentState = FREE;
        }
    }
}

void ElevatorController::passedFloor(int floor)
{
    setFloor(floor);
    currentText->append("Лифт преодолел " + QString::number(floor));
}

bool ElevatorController::nextFloor(int &floor)
{
    int step = -1;
    if (currentDirection == UP)
    {
        step = 1;
    }
    for (int i = currentFloor; i <= COUNT_OF_FLOORS && i > 0; i += step)
    {
        if (calls[i - 1])
        {
            floor = i;
            return true;
        }
    }
    step = -step;
    for (int i = currentFloor; i <= COUNT_OF_FLOORS && i > 0; i+= step)
    {
        if (calls[i - 1])
        {
            floor = i;
            return true;
        }
    }
    return false;
}
