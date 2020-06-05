#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QLabel>
#include <QListWidget>
#include "constants.h"
#include "qdebug.h"

class ElevatorDoors : public QObject
{
    Q_OBJECT
    enum stateOfDoors
    {
        OPENED,
        CLOSED,
        OPENNING,
        CLOSING
    };

public:
    explicit ElevatorDoors(QObject *parent = nullptr);
    void setDoorsLabel(QLabel* currentLabel);

signals:
    void doorsClosed();
    void doorsOpened();

public slots:
    void startOpeningDoors();
    void startClosingDoors();

private slots:
    void open();
    void close();

private:
    stateOfDoors currentState;

    QTimer timerForOpeningDoors;
    QTimer timerForClosingDoors;
    QTimer timerForStayingOpen;

    QLabel* doorsState;
    void setDoorsState();
};

#endif // DOORS_H
