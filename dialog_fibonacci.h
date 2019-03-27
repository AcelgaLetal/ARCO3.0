#ifndef DIALOG_FIBONACCI_H
#define DIALOG_FIBONACCI_H

#include <QDialog>

namespace Ui {
class Dialog_fibonacci;
}

class Dialog_fibonacci : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_fibonacci(QWidget *parent = nullptr);
    ~Dialog_fibonacci();
    void SetDatosLog(QString numero);

private slots:
    void on_pushButton_execFib_clicked();

    void on_pushButton_resetFib_clicked();

private:
    Ui::Dialog_fibonacci *ui;
};

#endif // DIALOG_FIBONACCI_H
