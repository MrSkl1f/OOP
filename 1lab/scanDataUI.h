#ifndef SCANDATAUI_H
#define SCANDATAUI_H

#include <QMainWindow>
#include "mainwindow.h"
#include <cstdlib>
#include "manager.h"
#include "ui_mainwindow.h"
#include "drawFigure.h"

void inputInfoTurn(Ui::MainWindow *ui, curManager &myManager);
void inputInfoScale(Ui::MainWindow *ui, curManager &myManager);
void inputInfoMove(Ui::MainWindow *ui, curManager &myManager);
void inputInfoDraw(Ui::MainWindow *ui, curManager &myManager);

#endif // SCANDATAUI_H
