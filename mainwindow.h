#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "client.h"



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
        void on_pbajouter_clicked();
    void on_pb_supp_clicked();
    void on_pbmodifier_clicked();


    void on_pbrechercher_clicked();



    void on_pbsms_clicked();

    void on_codesms_returnPressed();

private:
    Ui::MainWindow *ui;
    Client Ctmp;
};

#endif // MAINWINDOW_H
