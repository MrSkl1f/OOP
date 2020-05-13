#ifndef TURNFIGURE_H
#define TURNFIGURE_H

#include "figure.h"
#include "exceptions.h"
#include <math.h>

struct turnFigure
{
    double ox;
    double oy;
    double oz;
};

int turnPointsArray(curFigure &myFigure, turnFigure angles);
void turnPointsCycle(pointData &points, turnFigure angles);
void turnPoints(onePoint *curPoint, int curPos, turnFigure angles);
void turn(double &frstParam, double &scndParam, double angle);

#endif // TURNFIGURE_H
