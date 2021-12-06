#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QDialog>

namespace Ui {
class Notepad;
}

class Notepad : public QDialog
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();
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
    Ui::Notepad *ui;
    QString file_path;
};

#endif // NOTEPAD_H
