#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_fibonacci.h"
#include "dialog_byn.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_popup_Fib_clicked()
{
    Dialog_fibonacci dialog_fib;
    dialog_fib.setModal(true);
    dialog_fib.exec();
}

void MainWindow::on_pushButton_popoup_byn_clicked()
{
    Dialog_byn dialog_byn;
    dialog_byn.setModal(true);
    dialog_byn.exec();
}
