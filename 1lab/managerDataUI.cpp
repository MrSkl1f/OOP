#include "managerDataUI.h"
#include "scanDataUI.h"

int inputInfo(Ui::MainWindow *ui, infoTask &curTask, curManager &myManager)
{
    int errCode = NO_EXCEPTION;
    switch (curTask)
    {
        case FILE_NAME:
            break;
        case INFO_FOR_MOVE:
            inputInfoMove(ui, myManager);
            break;
        case INFO_FOR_SCALE:
            inputInfoScale(ui, myManager);
            break;
        case INFO_FOR_TURN:
            inputInfoTurn(ui, myManager);
            break;
        case INFO_FOR_DRAW:
            inputInfoDraw(ui, myManager);
            break;
        default:
            errCode = COMMAND_EXCEPTION;
    }

    return errCode;
}

