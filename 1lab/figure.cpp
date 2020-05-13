#include "figure.h"

curFigure initFigure(curFigure &myFigure)
{
    initPointsOfFigure(myFigure.points);
    initLinksOfFigure(myFigure.links);
    return myFigure;
}

void initPointsOfFigure(pointData &points)
{
    points.countOfPoints = 0;
    points.points = NULL;
}

void initLinksOfFigure(linkData &links)
{
    links.countOfLinks = 0;
    links.links = NULL;
}

int checkArrPoints(pointData points)
{
    return !points.points;
}
