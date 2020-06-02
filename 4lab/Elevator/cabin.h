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
        GOT_NEW_FLOOR,
        WAITING__FOR_CALL,
        WAITING_FOR_ENTRANCE
    };

public:
    explicit ElevatorCabin(QObject *parent = nullptr);
    void setStateLabels(QLabel* doorsLabel, QLabel *cabinLabel);
    void setText(QTextEdit* newText);

signals:
    void preparingForMoving();
    void crossingTheFloor(int floor, direction currentDirection);
    void reached_target(int floor);
    void cabin_stopped(int floor);

public slots:
    void movingOfCabin();
    void stopingOfCabin();
    void cabinSetNewFloor(int floor);


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
