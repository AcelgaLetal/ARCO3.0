#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetDatosLog(QString numero);

private slots:
    void on_pushButton_popup_Fib_clicked();

    void on_pushButton_popoup_byn_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage  *imageObject;

};

#endif // MAINWINDOW_H
