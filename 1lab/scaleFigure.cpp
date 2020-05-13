#include "scaleFigure.h"

int scalePointsArray(curFigure &myFigure, scaleFigure curScale)
{
    int codeError = NO_EXCEPTION;
    if (checkArrPoints(myFigure.points))
        return NO_ARR_EXCEPTION;
    scalePointsCycle(myFigure.points, curScale);
    return codeError;
}

void scalePointsCycle(pointData &points, scaleFigure curScale)
{
    for (int i = 0; i < points.countOfPoints; i++)
        scalePoints(points.points, i, curScale);
}

void scalePoints(onePoint *curPoint, int curPos, scaleFigure curScale)
{
    scalePoint(curPoint[curPos], curScale);
}

void scalePoint(onePoint &curPoint, scaleFigure curScale)
{
    curPoint.x *= curScale.kx;
    curPoint.y *= curScale.ky;
    curPoint.z *= curScale.kz;
}
