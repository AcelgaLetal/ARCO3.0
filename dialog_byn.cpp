#include "dialog_byn.h"
#include "ui_dialog_byn.h"
#include "mainwindow.h"
#include <QFileDialog>
#include<QImage>
#include<iostream>
#include <QElapsedTimer>

using namespace std;

QString origen_filePath;
QString destino_filePath;
int counter1 = 0;
float media1 = 0.0;

Dialog_byn::Dialog_byn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_byn)
{
    ui->setupUi(this);
}

Dialog_byn::~Dialog_byn()
{
    delete ui;
}

void Dialog_byn::on_pushButton_select_dir_origen_clicked()
{
    origen_filePath = QFileDialog::getOpenFileName(this, tr("Escoja una imagen"), "/", tr("JPEG (*.jpg *.jpeg);;PNG (*.png)"));
    destino_filePath = QFileDialog::getSaveFileName(this, tr("Escoja donde guardar la imagen"),"", tr("JPEG (*.jpg *.jpeg);;PNG (*.png)"));

}

void Dialog_byn::on_pushButton_exec_byn_clicked()
{
    QElapsedTimer timer;

    QImage *image;
    int tiempo = 0;
    image = new QImage();

    timer.start();

    image->load(origen_filePath, "JPG");

    QColor changeColor;
    for(int x = 0; x <image->width(); x++)
    {
        for(int y = 0; y < image->height(); y++)
        {
            changeColor = QColor(image->pixel(x, y));
            float grey = (changeColor.red() + changeColor.green() + changeColor.blue()) / 3;
            image->setPixel(x, y, QColor(grey, grey, grey).rgb());
        }
    }

    image->save(destino_filePath);

    tiempo = timer.elapsed();

    switch(counter1)
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
    if(counter1 < 5)
    {
        cout<<counter1<<endl;
        media1 += tiempo / 5.0;
        counter1++;
    }
    if(counter1 == 5)
    {
        cout<<media1<<endl;
        ui->lineEdit_out_media_byn->setText(QString::number(media1));
    }
}

void Dialog_byn::on_pushButton_reset_byn_clicked()
{
    ui->lineEdit_out_t1->clear();
    ui->lineEdit_out_t2->clear();
    ui->lineEdit_out_t3->clear();
    ui->lineEdit_out_t4->clear();
    ui->lineEdit_out_t5->clear();
    ui->lineEdit_out_media_byn->clear();
    media1 = 0.0;
    counter1 = 0;
}
