#include "cabin.h"

ElevatorCabin::ElevatorCabin(QObject *parent) : QObject(parent)
{
    currentDirection = STAY;
    currentFloor = 1;
    currentState = WAITING_FOR_CALL;

    timerForCrossingFloor.setSingleShot(true);
    QObject::connect(&timerForCrossingFloor, SIGNAL(timeout()), this, SLOT(checkMoving()));

    QObject::connect(this, SIGNAL(cabinStopped(int)), &doors, SLOT(startOpeningDoors()));
    QObject::connect(this, SIGNAL(preparingForMoving()), &doors, SLOT(startClosingDoors()));

    QObject::connect(&doors, SIGNAL(doorsClosed()), this, SLOT(checkMoving()));

    QObject::connect(this, SIGNAL(freeCabin()), this, SLOT(waitingForCall()));
    QObject::connect(this, SIGNAL(reachedNewFloor()), this, SLOT(waitingForEntrance()));
    QObject::connect(this, SIGNAL(continueMoving()), this, SLOT(movingOfCabin()));
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
        case WAITING_FOR_CALL:
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

void ElevatorCabin::checkMoving()
{
    if (currentState == MOVING || currentState == GOT_NEW_FLOOR)
    {
        currentState = CHECK_MOVING;
        if (currentFloor == newFloor)
            emit reachedNewFloor();
        else
        {
            emit crossingTheFloor(currentFloor);
            emit continueMoving();
        }
    }
    else
    {
        currentState = CHECK_MOVING;
        emit freeCabin();
    }
}

void ElevatorCabin::movingOfCabin()
{
    currentState = MOVING;
    setCabinState();
    timerForCrossingFloor.start(CROSSING_FLOOR);
    currentFloor += currentDirection;
}

void ElevatorCabin::waitingForCall()
{
    currentState = WAITING_FOR_CALL;
    setCabinState();
    currentText->append("Лифт находится в режиме ожидания.");
}

void ElevatorCabin::waitingForEntrance()
{
    currentState = WAITING_FOR_ENTRANCE;
    setCabinState();
    currentText->append("Лифт остановился на этаже " + QString::number(currentFloor) + ".");
    emit cabinStopped(currentFloor);
}

void ElevatorCabin::gotNewFloor(int floor)
{
    currentState = GOT_NEW_FLOOR;
    setCabinState();
    newFloor = floor;
    if (currentFloor > newFloor)
        currentDirection = DOWN;
    else
        currentDirection = UP;
    emit preparingForMoving();
}

