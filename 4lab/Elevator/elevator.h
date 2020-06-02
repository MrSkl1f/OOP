#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QTextEdit>
#include "cabin.h"
#include "controller.h"

class Elevator : public QObject
{
    Q_OBJECT

public:
    Elevator();
    void addNewCall(int floor);
    void setLabels(QLabel* doorsLabel, QLabel *cabinLabel, QLabel *floorLabel);
    void setTextEdit(QTextEdit* newText);
private:
    ElevatorController elevatorController;
    ElevatorCabin elevatorCabin;
};

#endif // ELEVATOR_H
