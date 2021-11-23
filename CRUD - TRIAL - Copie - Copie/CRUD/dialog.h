#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_New_clicked();

    void on_Open_clicked();

    void on_Save_clicked();

    void on_pushButton_4_clicked();

    void on_Copy_clicked();

    void on_Paste_clicked();

    void on_Cut_clicked();

    void on_pushButton_10_clicked();

    void on_Redo_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QString file_path;

};

#endif // DIALOG_H
