#include "cabin.h"

ElevatorCabin::ElevatorCabin(QObject *parent) : QObject(parent)
{
    currentDirection = STAY;
    currentFloor = 1;
    currentState = WAITING__FOR_CALL;

    timerForCrossingFloor.setSingleShot(true);

    QObject::connect(this, SIGNAL(reached_target(int)), this, SLOT(stopingOfCabin()));
    QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors, SLOT(startOpeningDoors()));
    QObject::connect(&timerForCrossingFloor, SIGNAL(timeout()), this, SLOT(movingOfCabin()));
    QObject::connect(this, SIGNAL(preparingForMoving()), &doors, SLOT(startClosingDoors()));
    QObject::connect(&doors, SIGNAL(doorsClosed()), this, SLOT(movingOfCabin()));
}

void ElevatorCabin::setStateLabels(QLabel *doorsLabel, QLabel *cabinLabel)
{
    doors.setDoorsLabel(doorsLabel);
    cabinState = cabinLabel;
}

void ElevatorCabin::setCabinState()
{
    switch (currentState)
    {
        case MOVING:
            cabinState->setText("Движется");
            break;
        case GOT_NEW_FLOOR:
            cabinState->setText("Получил новый вызов");
            break;
        case WAITING__FOR_CALL:
            cabinState->setText("Ждет вызова");
            break;
        case WAITING_FOR_ENTRANCE:
            cabinState->setText("Ждет входа людей");
            break;
        default:
            cabinState->setText("Ждет вызова");
            break;
    }
}

void ElevatorCabin::setText(QTextEdit *newText)
{
    currentText = newText;
}

void ElevatorCabin::movingOfCabin()
{
    if (currentState == GOT_NEW_FLOOR)
    {
        if (currentFloor == newFloor)
        {
            emit reached_target(currentFloor);
        }
        else
        {
            currentState = MOVING;
            setCabinState();
            timerForCrossingFloor.start(CROSSING_FLOOR);
        }
    }
    else if (currentState == MOVING)
    {
        currentFloor += currentDirection;
        if (currentFloor == newFloor)
        {
            emit reached_target(currentFloor);
        }
        else
        {
            emit crossingTheFloor(currentFloor, currentDirection);
            timerForCrossingFloor.start(CROSSING_FLOOR);
        }
    }
    else
    {
        currentState = WAITING__FOR_CALL;
        setCabinState();
        currentText->append("Лифт находится в режиме ожидания.");
    }
}

void ElevatorCabin::stopingOfCabin()
{
    currentState = WAITING_FOR_ENTRANCE;
    setCabinState();
    currentText->append("Лифт остановился на этаже " + QString::number(currentFloor) + ".");
    emit cabin_stopped(currentFloor);
}

void ElevatorCabin::cabinSetNewFloor(int floor)
{
    currentState = GOT_NEW_FLOOR;
    setCabinState();
    newFloor = floor;
    if (currentFloor == newFloor)
    {
        emit reached_target(floor);
    }
    else
    {
        if (currentFloor > newFloor)
            currentDirection = DOWN;
        else
            currentDirection = UP;
        emit preparingForMoving();
    }
}
