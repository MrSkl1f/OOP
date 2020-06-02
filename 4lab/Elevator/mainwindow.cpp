#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->append("Лифт находится на первом этаже, двери закрыты.");
    ui->textEdit->append("Лифт находится в режиме ожидания.");
    elevator.setLabels(ui->label_6, ui->label_5, ui->label_8);
    elevator.setTextEdit(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_cabin_1_clicked()
{
    ui->textEdit->append("На 1 этаже был вызван лифт.");
    elevator.addNewCall(1);
}

void MainWindow::on_button_cabin_2_clicked()
{
    ui->textEdit->append("На 2 этаже был вызван лифт.");
    elevator.addNewCall(2);
}

void MainWindow::on_button_cabin_3_clicked()
{
    ui->textEdit->append("На 3 этаже был вызван лифт.");
    elevator.addNewCall(3);
}

void MainWindow::on_button_cabin_4_clicked()
{
    ui->textEdit->append("На 4 этаже был вызван лифт.");
    elevator.addNewCall(4);
}

void MainWindow::on_button_cabin_5_clicked()
{
    ui->textEdit->append("На 5 этаже был вызван лифт.");
    elevator.addNewCall(5);
}

void MainWindow::on_button_floor_1_clicked()
{
    ui->textEdit->append("В лифте нажали кнопку 1.");
    elevator.addNewCall(1);
}

void MainWindow::on_button_floor_2_clicked()
{
    ui->textEdit->append("В лифте нажали кнопку 2.");
    elevator.addNewCall(2);
}

void MainWindow::on_button_floor_3_clicked()
{
    ui->textEdit->append("В лифте нажали кнопку 3.");
    elevator.addNewCall(3);
}

void MainWindow::on_button_floor_4_clicked()
{
    ui->textEdit->append("В лифте нажали кнопку 4.");
    elevator.addNewCall(4);
}

void MainWindow::on_button_floor_5_clicked()
{
    ui->textEdit->append("В лифте нажали кнопку 5.");
    elevator.addNewCall(5);
}


