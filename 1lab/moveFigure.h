#ifndef MOVEFIGURE_H
#define MOVEFIGURE_H

#include "figure.h"
#include "exceptions.h"

struct moveFigure
{
    double dx;
    double dy;
    double dz;
};

int movePointsArray(curFigure &myFigure, moveFigure curMove);
void movePoint(onePoint &curPoint, moveFigure curMove);
void movePointsCycle(pointData &points, moveFigure curMove);
void movePoints(onePoint *curPoint, int curPos, moveFigure curMove);

#endif // MOVEFIGURE_H
