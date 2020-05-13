#include "scanDataUI.h"

void inputInfoMove(Ui::MainWindow *ui, curManager &myManager)
{
    myManager.curMove.dx = ui->doubleSpinBox->value();
    myManager.curMove.dy = ui->doubleSpinBox_2->value();
    myManager.curMove.dz = ui->doubleSpinBox_3->value();
}

void inputInfoScale(Ui::MainWindow *ui, curManager &myManager)
{
    myManager.curScale.kx = ui->doubleSpinBox_4->value();
    myManager.curScale.ky = ui->doubleSpinBox_5->value();
    myManager.curScale.kz = ui->doubleSpinBox_6->value();
}

void inputInfoTurn(Ui::MainWindow *ui, curManager &myManager)
{
    myManager.curTurn.ox = ui->doubleSpinBox_9->value();
    myManager.curTurn.oy = ui->doubleSpinBox_8->value();
    myManager.curTurn.oz = ui->doubleSpinBox_7->value();
}

void inputInfoDraw(Ui::MainWindow *ui, curManager &myManager)
{
    myManager.curGraph.graphViewUI = ui->graphicsView;
    myManager.curGraph.height = ui->graphicsView->height();
    myManager.curGraph.width = ui->graphicsView->width();
}
