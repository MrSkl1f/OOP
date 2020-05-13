#include "manager.h"

int manager(curManager &myManager)
{
    int errCode = NO_EXCEPTION;
    static curFigure myFigure = initFigure(myFigure);
    switch (myManager.currectTask)
    {
        case LOAD_FROM_FILE:
            errCode = inputData(myFigure, myManager.curName);
            break;
        case MOVE:
            errCode = movePointsArray(myFigure, myManager.curMove);
            break;
        case SCALE:
            errCode = scalePointsArray(myFigure, myManager.curScale);
            break;
        case TURN:
            errCode = turnPointsArray(myFigure, myManager.curTurn);
            break;
        case DRAW:
            errCode = drawFigure(myFigure, myManager.curGraph);
            break;
        case FREE_MEMORY:
            freeMemoryWhenExit(myFigure);
            break;
        default:
            errCode = COMMAND_EXCEPTION;
    }
    return errCode;
}
