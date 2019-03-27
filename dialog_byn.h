#ifndef DIALOG_BYN_H
#define DIALOG_BYN_H

#include <QDialog>

namespace Ui {
class Dialog_byn;
}

class Dialog_byn : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_byn(QWidget *parent = nullptr);
    ~Dialog_byn();

private slots:
    void on_pushButton_select_dir_origen_clicked();

    void on_pushButton_exec_byn_clicked();

    void on_pushButton_reset_byn_clicked();

private:
    Ui::Dialog_byn *ui;
};

#endif // DIALOG_BYN_H
