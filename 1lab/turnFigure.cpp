#include "turnFigure.h"

int turnPointsArray(curFigure &myFigure, turnFigure angles)
{
    int codeError = NO_EXCEPTION;
    if (checkArrPoints(myFigure.points))
        return NO_ARR_EXCEPTION;
    turnPointsCycle(myFigure.points, angles);
    return codeError;
}

void turnPointsCycle(pointData &points, turnFigure angles)
{
    for (int i = 0; i < points.countOfPoints; i++)
        turnPoints(points.points, i, angles);
}

void turnPoints(onePoint *curPoint, int curPos, turnFigure angles)
{
    turn(curPoint[curPos].y, curPoint[curPos].z, angles.ox);
    turn(curPoint[curPos].x, curPoint[curPos].z, angles.oy);
    turn(curPoint[curPos].x, curPoint[curPos].y, angles.oz);
}

void turn(double &frstParam, double &scndParam, double angle)
{
    double saveFrst = frstParam;
    double saveScnd = scndParam;
    double sinParam = sin(angle * M_PI / 180);
    double cosParam = cos(angle * M_PI / 180);

    frstParam = saveFrst * cosParam + saveScnd * sinParam;
    scndParam = -saveFrst * sinParam + saveScnd * cosParam;
}
