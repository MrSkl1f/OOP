#ifndef ALLOCATIONMEMORY_H
#define ALLOCATIONMEMORY_H

#include <stdlib.h>
#include "exceptions.h"
#include "figure.h"

int allocMemoryForFigure(pointData &points, linkData &links);
int allocMemoryForPoints(onePoint **points, int countOfPoints);
int allocMemoryForLinks(oneLink **links, int countOfLinks);
void freeMemory(pointData &points, linkData &links);
void freePoints(onePoint **points);
void freeLinks(oneLink **links);
void freeMemoryWhenExit(curFigure &myFigure);

#endif // ALLOCATIONMEMORY_H
