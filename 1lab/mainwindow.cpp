#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonMove_clicked()
{
    printf("Yes\n");
}

void MainWindow::on_pushButtonScale_clicked()
{
    printf("Yes\n");
}

void MainWindow::on_pushButtonTurn_clicked()
{
    printf("Yes\n");
}

void MainWindow::on_pushButtonInputFile_clicked()
{
    Manager myManager;
    myManager.task = INPUT_DATA_FROM_FILE;
    myManager.input.filename = ui->lineEdit_10->text().toStdString().c_str();

    int errorCode = manager(myManager);
}

int drawFigure(Ui::MainWindow *ui)
{
    graphView info;
    info.graphView = ui->graphicsView;
    info.height = ui->graphicsView->height();
    info.width = ui->graphicsView->width();

    Manager myManager;
    myManager.task = DRAW;
    myManager.curView = info;

    int codeError = manager(myManager);
    return codeError;
}
