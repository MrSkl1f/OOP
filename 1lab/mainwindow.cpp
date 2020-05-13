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
    curManager myManager;
    myManager.currectTask = FREE_MEMORY;
    manager(myManager);
    delete ui;
}

void callManager(Ui::MainWindow *ui, infoTask &curTask, curManager &myManager)
{

    int errCode = inputInfo(ui, curTask, myManager);
    if (!errCode)
        errCode = manager(myManager);
    if (!errCode)
    {
        curTask = INFO_FOR_DRAW;
        myManager.currectTask = DRAW;
        errCode = inputInfo(ui, curTask, myManager);
        if (!errCode)
            errCode = manager(myManager);
    }
    if (errCode)
        showException(errCode);
}

void MainWindow::on_pushButtonMove_clicked()
{
    infoTask task = INFO_FOR_MOVE;
    curManager myManager;
    myManager.currectTask = MOVE;
    callManager(ui, task, myManager);
}

void MainWindow::on_pushButtonScale_clicked()
{
    infoTask task = INFO_FOR_SCALE;
    curManager myManager;
    myManager.currectTask = SCALE;
    callManager(ui, task, myManager);
}

void MainWindow::on_pushButtonTurn_clicked()
{
    infoTask task = INFO_FOR_TURN;
    curManager myManager;
    myManager.currectTask = TURN;
    callManager(ui, task, myManager);
}

void MainWindow::on_pushButtonInputFile_clicked()
{
    infoTask task = FILE_NAME;
    curManager myManager;
    QString filename_string;
    filename_string = ui->lineEdit->text();
    myManager.curName.filename = filename_string.toStdString().c_str();
    myManager.currectTask = LOAD_FROM_FILE;
    callManager(ui, task, myManager);
}


