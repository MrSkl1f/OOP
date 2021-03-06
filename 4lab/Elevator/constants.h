#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QTextEdit>
#include <QTimer>

#define CROSSING_FLOOR 2000
#define CLOSING_DOOR 2500
#define OPENING_DOOR 2500
#define WAITING_TIME 2500
#define COUNT_OF_FLOORS 5

enum direction
{
    UP = 1,
    DOWN = -1,
    STAY = 0
};

#endif // CONSTANTS_H
