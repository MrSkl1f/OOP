#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QString>
#include "constants.h"
#include "doors.h"

class ElevatorCabin : public QObject
{
    Q_OBJECT
    enum stateOfCabin
    {
        MOVING,
        CHECK_MOVING,
        GOT_NEW_FLOOR,
        WAITING_FOR_CALL,
        WAITING_FOR_ENTRANCE
    };

public:
    explicit ElevatorCabin(QObject *parent = nullptr);
    void setStateLabels(QLabel* doorsLabel, QLabel *cabinLabel);
    void setText(QTextEdit* newText);

signals:
    void preparingForMoving();
    void crossingTheFloor(int floor);
    void reachedNewFloor();
    void cabinStopped(int floor);
    void freeCabin();
    void continueMoving();

public slots:
    void movingOfCabin();
    void gotNewFloor(int floor);

private slots:
    void waitingForCall();
    void waitingForEntrance();
    void checkMoving();

private:
    int currentFloor;
    int newFloor;

    stateOfCabin currentState;

    direction currentDirection;

    ElevatorDoors doors;

    QTimer timerForCrossingFloor;

    QLabel* cabinState;
    QTextEdit* currentText;
    void setCabinState();
};

#endif // CABIN_H
