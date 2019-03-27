#include "dialog_fibonacci.h"
#include "ui_dialog_fibonacci.h"

#include <iostream>
#include <ctime>
#include <QFile>
#include <QTextStream>
#include <QScrollBar>
#include <QDateTime>
#include <QElapsedTimer>

using namespace std;

QFile logd("fibonacci.txt");
int counter = 0;
float media = 0.0;

Dialog_fibonacci::Dialog_fibonacci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_fibonacci)
{
    ui->setupUi(this);
}

Dialog_fibonacci::~Dialog_fibonacci()
{
    delete ui;
}

void Dialog_fibonacci::on_pushButton_execFib_clicked()
{
    QElapsedTimer timer;

    unsigned int numFib = 0;
    unsigned aux = 1;
    unsigned aux2 = 0;
    int tiempo = 0;

    timer.start();

    logd.open(QIODevice::WriteOnly);

    SetDatosLog(QString::number(0));
    SetDatosLog(QString::number(1));

    for(int i = 0; i < 1000; i++)
    {
        aux2 = numFib + aux;
        numFib = aux;
        aux = aux2;

        SetDatosLog(QString::number(aux2));
    }
    logd.close();

    tiempo = timer.elapsed();

    switch(counter)
    {
        case 0:
            ui->lineEdit_out_t1->setText(QString::number(tiempo) + "ms");
            break;
        case 1:
            ui->lineEdit_out_t2->setText(QString::number(tiempo) + "ms");
            break;
        case 2:
            ui->lineEdit_out_t3->setText(QString::number(tiempo) + "ms");
            break;
        case 3:
            ui->lineEdit_out_t4->setText(QString::number(tiempo) + "ms");
            break;
        case 4:
            ui->lineEdit_out_t5->setText(QString::number(tiempo) + "ms");
            break;
    }
    if(counter < 5)
    {
        cout<<counter<<endl;
        media += tiempo / 5.0;
        counter++;
    }
    if(counter == 5)
    {
        cout<<media<<endl;
        ui->lineEdit_out_media->setText(QString::number(media));
    }

}

void Dialog_fibonacci::on_pushButton_resetFib_clicked()
{
    ui->lineEdit_out_t1->clear();
    ui->lineEdit_out_t2->clear();
    ui->lineEdit_out_t3->clear();
    ui->lineEdit_out_t4->clear();
    ui->lineEdit_out_t5->clear();
    ui->lineEdit_out_media->clear();
    media = 0.0;
    counter = 0;
}
void Dialog_fibonacci::SetDatosLog(QString numero)
{
    QTextStream escribir(&logd);
    escribir<<numero;
    escribir<<"\n";
}
