#include "doors.h"

ElevatorDoors::ElevatorDoors(QObject *parent) : QObject(parent)
{
    currentState = CLOSED;

    timerForStayingOpen.setInterval(WAITING_TIME);
    timerForStayingOpen.setSingleShot(true);
    timerForOpeningDoors.setSingleShot(true);
    timerForClosingDoors.setSingleShot(true);

    QObject::connect(&timerForOpeningDoors, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&timerForClosingDoors, SIGNAL(timeout()), this, SLOT(close()));
    QObject::connect(this, SIGNAL(doorsOpened()), &timerForStayingOpen, SLOT(start()));
    QObject::connect(&timerForStayingOpen, SIGNAL(timeout()), this, SLOT(startClosingDoors()));
}

void ElevatorDoors::setDoorsState()
{
    switch (currentState)
    {
        case OPENED:
            doorsState->setText("Открыты");
            break;
        case CLOSED:
            doorsState->setText("Закрыты");
            break;
        case OPENNING:
            doorsState->setText("Открываются");
            break;
        case CLOSING:
            doorsState->setText("Закрываются");
            break;
        default:
            doorsState->setText("none");
            break;
    }
}

void ElevatorDoors::setDoorsLabel(QLabel* currentLabel)
{
    doorsState = currentLabel;
    setDoorsState();
}

void ElevatorDoors::startOpeningDoors()
{
    if (currentState == CLOSED)
    {
        currentState = OPENNING;
        setDoorsState();
        timerForOpeningDoors.start(OPENING_N_CLOSING);
    }
    if (currentState == CLOSING)
    {
        currentState = OPENNING;
        setDoorsState();
        int remainingTime = timerForClosingDoors.remainingTime();
        timerForClosingDoors.stop();
        timerForOpeningDoors.start(OPENING_N_CLOSING - remainingTime);
    }
}

void ElevatorDoors::startClosingDoors()
{
    if (currentState == OPENED)
    {
        currentState = CLOSING;
        setDoorsState();
        timerForClosingDoors.start(OPENING_N_CLOSING);
    }
    else if (currentState == CLOSED)
        emit doorsClosed();
}

void ElevatorDoors::open()
{
    if (currentState == OPENNING)
    {
        currentState = OPENED;
        setDoorsState();
        emit doorsOpened();
    }
}

void ElevatorDoors::close()
{
    if (currentState == CLOSING)
    {
        currentState = CLOSED;
        setDoorsState();
        emit doorsClosed();
    }
}
