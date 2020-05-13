#include "allocationMemory.h"

int allocMemoryForFigure(pointData &points, linkData &links)
{
    int errCode = NO_EXCEPTION;
    errCode = allocMemoryForPoints(&points.points, points.countOfPoints);
    if (errCode)
        return errCode;
    errCode = allocMemoryForLinks(&links.links, links.countOfLinks);
    if (errCode)
    {
        freePoints(&points.points);
        return errCode;
    }
    return errCode;
}

int allocMemoryForPoints(onePoint **points, int countOfPoints)
{
    int errCode = NO_EXCEPTION;
    *points = (onePoint *)calloc(countOfPoints, sizeof(onePoint));
    if (!*points)
        errCode = ALLOC_EXCEPION;
    return errCode;
}

int allocMemoryForLinks(oneLink **links, int countOfLinks)
{
    int errCode = NO_EXCEPTION;
    *links = (oneLink *)calloc(countOfLinks, sizeof(oneLink));
    if (!*links)
        errCode = ALLOC_EXCEPION;
    return errCode;
}

void freeMemoryWhenExit(curFigure &myFigure)
{
    freeMemory(myFigure.points, myFigure.links);
}

void freeMemory(pointData &points, linkData &links)
{
    freePoints(&points.points);
    freeLinks(&links.links);
}

void freePoints(onePoint **points)
{
    if (*points)
        free(*points);
}

void freeLinks(oneLink **links)
{
    if (*links)
        free(*links);
}
