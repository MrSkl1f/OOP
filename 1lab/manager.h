#ifndef MANAGER_H
#define MANAGER_H

#include "inputDataFromFile.h"
#include "moveFigure.h"
#include "turnFigure.h"
#include "scaleFigure.h"
#include "drawFigure.h"
#include "exceptions.h"
#include "figure.h"

enum task
{
    LOAD_FROM_FILE,
    DRAW,
    TURN,
    MOVE,
    SCALE,
    FREE_MEMORY
};

struct curManager
{
    task currectTask;
    union
    {
        struct loadDataFromFile curName;
        struct moveFigure curMove;
        struct scaleFigure curScale;
        struct turnFigure curTurn;
        struct graphView curGraph;
    };
};

int manager(curManager &myManager);

#endif // MANAGER_H
