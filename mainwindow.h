#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "client.h"
#include <QCompleter>
#include <QDirModel>


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

    void on_radioButton_clicked();



private:
    Ui::MainWindow *ui;
    Client Ctmp;
    QCompleter* Model_Completer, Model_Completer1;

};

#endif // MAINWINDOW_H
