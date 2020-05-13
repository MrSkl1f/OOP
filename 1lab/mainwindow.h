#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manager.h"
#include "managerDataUI.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonMove_clicked();

    void on_pushButtonScale_clicked();

    void on_pushButtonTurn_clicked();

    void on_pushButtonInputFile_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
