#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector>
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
    void set_new_target(int floor);
    void setFloorLabel(QLabel* currentLabel);
    void setText(QTextEdit* newText);

signals:
    void setNewFloor(int floor);

public slots:
    void achievedFloor(int floor);
    void passedFloor(int floor);

private:
    int currentFloor;
    bool calls[COUNT_OF_FLOORS];
    stateOfController currentState;
    direction currentDirection;
    bool nextFloor(int &floor);
    QLabel* currentFloorLabel;
    QTextEdit* currentText;
    void setFloor(int floor);
};

#endif // CONTROLLER_H
