#include "moveFigure.h"

int movePointsArray(curFigure &myFigure, moveFigure curMove)
{
    int codeError = NO_EXCEPTION;
    if (checkArrPoints(myFigure.points))
        return NO_ARR_EXCEPTION;
    movePointsCycle(myFigure.points, curMove);
    return codeError;
}

void movePointsCycle(pointData &points, moveFigure curMove)
{
    for (int i = 0; i < points.countOfPoints; i++)
        movePoints(points.points, i, curMove);
}

void movePoints(onePoint *curPoint, int curPos, moveFigure curMove)
{
    movePoint(curPoint[curPos], curMove);
}

void movePoint(onePoint &curPoint, moveFigure curMove)
{
    curPoint.x += curMove.dx;
    curPoint.y += curMove.dy;
    curPoint.z += curMove.dz;
}
