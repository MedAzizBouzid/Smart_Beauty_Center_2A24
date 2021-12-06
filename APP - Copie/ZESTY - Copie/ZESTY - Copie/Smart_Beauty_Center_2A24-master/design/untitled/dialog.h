#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "employe.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    bool Get_close(){return e;};
    void Set_close(bool val){e=val;};

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    Employe empymp;
    bool e;

};

#endif // DIALOG_H
