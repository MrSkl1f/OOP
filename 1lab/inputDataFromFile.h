#ifndef INPUTDATAFROMFILE_H
#define INPUTDATAFROMFILE_H

#include "figure.h"
#include "exceptions.h"
#include "allocationMemory.h"
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include "inputPoints.h"
#include "inputLinks.h"

#define FILENAME "cube.txt"
#define COUNT_OF_POINTS 8
#define COUNT_OF_LINKS 12

struct loadDataFromFile
{
    const char *filename;
};

int inputData(curFigure &myFigure, loadDataFromFile curName);
int readCountOfPointsAndLinks(FILE *curFile, pointData &points, linkData &links);
int copyFigure(int errCode, pointData newPoints, linkData newLinks, pointData &mainPoints, linkData &mainLinks);

#endif // INPUTDATAFROMFILE_H
