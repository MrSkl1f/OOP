#ifndef TRANSFORMPOINTS_H
#define TRANSFORMPOINTS_H

#include "figure.h"
#include "exceptions.h"
#include "drawFigure.h"
#include <math.h>

struct coords
{
    double x;
    double y;
    double z;
};

coords getDot(onePoint point);
coords pointTransform(coords &curPoint, graphView drawInfo);
void drawLine(graphView drawInfo, int x1, int x2, int y1, int y2);
void drawLinks(curFigure &myFigure, graphView &drawInfo);
int countPosFrom(oneLink *links, int i);
int countPosTo(oneLink *links, int i);
coords takeDot(onePoint *points, int curPos);
void drawCurLine(pointData points, linkData links, graphView drawInfo, int i);

#endif // TRANSFORMPOINTS_H
