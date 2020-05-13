#include "inputDataFromFile.h"

int inputData(curFigure &myFigure, loadDataFromFile curName)
{
    int errCode = NO_EXCEPTION;
    curFigure newFigure = initFigure(newFigure);
    FILE *curFile = fopen(curName.filename, "r");
    if (!curFile)
        errCode = FILE_READING_EXCEPTION;
    else
        errCode = readCountOfPointsAndLinks(curFile, newFigure.points, newFigure.links);

    if (!errCode)
        errCode = allocMemoryForFigure(newFigure.points, newFigure.links);

    if (!errCode)
        errCode = readAllPoints(newFigure.points, curFile);

    if (!errCode)
        errCode = readAllLinks(newFigure.links, curFile);

    if (errCode != FILE_READING_EXCEPTION)
        fclose(curFile);

    if (errCode)
        freeMemory(newFigure.points, newFigure.links);

    errCode = copyFigure(errCode, newFigure.points, newFigure.links, myFigure.points, myFigure.links);
    return errCode;
}

int copyFigure(int errCode, pointData newPoints, linkData newLinks, pointData &mainPoints, linkData &mainLinks)
{
    if (errCode)
        return errCode;
    freeMemory(mainPoints, mainLinks);
    mainPoints = newPoints;
    mainLinks = newLinks;
    return errCode;
}

int readCountOfPointsAndLinks(FILE *curFile, pointData &points, linkData &links)
{
    int errCode = NO_EXCEPTION;
    errCode = readCountOfPoints(curFile, points.countOfPoints);
    if (errCode)
        return errCode;
    errCode = readCountOfLinks(curFile, links.countOfLinks);
    return errCode;
}
