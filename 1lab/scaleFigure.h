#ifndef SCALEFIGURE_H
#define SCALEFIGURE_H

#include "figure.h"
#include "exceptions.h"

struct scaleFigure
{
    double kx;
    double ky;
    double kz;
};

void scalePoint(onePoint &curPoint, scaleFigure curScale);
int scalePointsArray(curFigure &myFigure, scaleFigure curScale);
void scalePointsCycle(pointData &points, scaleFigure curScale);
void scalePoints(onePoint *curPoint, int curPos, scaleFigure curScale);

#endif // SCALEFIGURE_H
