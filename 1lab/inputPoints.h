#ifndef INPUTPOINTS_H
#define INPUTPOINTS_H

#include "figure.h"
#include "exceptions.h"
#include <cstdio>

int readCountOfPoints(FILE *curFile, int &countOfPoints);
int readAllPoints(pointData &info, FILE *curFile);
int inputPoint(FILE *curFile, onePoint *curPoint, int curPos);
int inputCurPoint(FILE *curFile, onePoint &curPoint);

#endif // INPUTPOINTS_H
