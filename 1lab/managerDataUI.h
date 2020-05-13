#ifndef MANAGERDATAUI_H
#define MANAGERDATAUI_H

#include <QMainWindow>
#include "mainwindow.h"
#include <cstdlib>
#include "manager.h"
#include "ui_mainwindow.h"
#include "drawFigure.h"

enum infoTask
{
    FILE_NAME,
    INFO_FOR_MOVE,
    INFO_FOR_TURN,
    INFO_FOR_SCALE,
    INFO_FOR_DRAW
};

int inputInfo(Ui::MainWindow *ui, infoTask &curTask, curManager &myManager);

#endif // MANAGERDATAUI_H
