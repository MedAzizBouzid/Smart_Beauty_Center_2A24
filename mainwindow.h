#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "client.h"
#include <QCompleter>
#include <QDirModel>
#include "smtp.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
        void on_pbajoutermariem_clicked();
    void on_pb_suppmariem_clicked();
    void on_pbmodifiermariem_clicked();


    void on_pbrecherchermariem_clicked();


    void on_codemailmariem_returnPressed();


    void on_pb_mailmariem_clicked();

    void sendMail();
        void mailSent(QString);


        void on_calendarWidgetmariem_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;
    Client Ctmp;
    QCompleter* Model_Completer, Model_Completer1;

};

#endif // MAINWINDOW_H
