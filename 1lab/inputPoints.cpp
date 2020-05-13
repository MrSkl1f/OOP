#include "inputPoints.h"

int readCountOfPoints(FILE *curFile, int &countOfPoints)
{
    int errCode = NO_EXCEPTION;
    if (fscanf(curFile, "%d", &countOfPoints) != 1)
        return FILE_FORMAT_EXCEPTION;
    return errCode;
}

int readAllPoints(pointData &info, FILE *curFile)
{
    int errCode = NO_EXCEPTION;
    for (int i = 0; i < info.countOfPoints && !errCode; i++)
        errCode = inputPoint(curFile, info.points, i);
    return errCode;
}

int inputPoint(FILE *curFile, onePoint *curPoint, int curPos)
{
    int errCode = NO_EXCEPTION;
    if (inputCurPoint(curFile, curPoint[curPos]) != 4)
        return FILE_FORMAT_EXCEPTION;
    return errCode;
}

int inputCurPoint(FILE *curFile, onePoint &curPoint)
{
    return fscanf(curFile, "%lf %lf %lf %d", &(curPoint.x), &(curPoint.y), &(curPoint.z), &(curPoint.number));
}
