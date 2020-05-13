#ifndef FIGURE_H
#define FIGURE_H

#include <cstdlib>

struct onePoint
{
    double x;
    double y;
    double z;
    int number;
};

struct pointData
{
    int countOfPoints;
    struct onePoint *points;
};

struct oneLink
{
    int from;
    int to;
};

struct linkData
{
    int countOfLinks;
    struct oneLink *links;
};

struct curFigure
{
    struct pointData points;
    struct linkData links;
};

curFigure initFigure(curFigure &myFigure);
void initPointsOfFigure(pointData &points);
void initLinksOfFigure(linkData &links);
int checkArrPoints(pointData points);

#endif // FIGURE_H
