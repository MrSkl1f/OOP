#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QLabel>
#include <QTextEdit>
#include "constants.h"
#include "qdebug.h"

class ElevatorController : public QObject
{
    Q_OBJECT

    enum stateOfController
    {
        FREE,
        BUSY
    };

public:
    explicit ElevatorController(QObject *parent = nullptr);
    void setNewFloor(int floor);
    void setFloorLabel(QLabel* currentLabel);
    void setText(QTextEdit* newText);

signals:
    void sendNewFloor(int floor);
    void setNewTask(int floor);

public slots:
    void achievedFloor(int floor);
    void passedFloor(int floor);

private slots:
    void gotNewTask(int floor);

private:
    int currentFloor;
    bool floorCalls[COUNT_OF_FLOORS];

    stateOfController currentState;

    direction currentDirection;

    bool nextFloor(int &floor);

    QLabel* currentFloorLabel;
    QTextEdit* currentText;

    void setFloor(int floor);
};

#endif // CONTROLLER_H
