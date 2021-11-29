#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "arduino.h"
#include <QMainWindow>
#include"produit.h"
#include <QDirModel>
#include <QCompleter>
#include<QSystemTrayIcon>
#include "qrcode.h"

namespace Ui {
class MainWindow;
}
class QSystemTrayIcon;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouterbouzid_clicked();

    void on_pb_supprimerbouzid_clicked();


    void on_pb_modifierbouzid_clicked();

    void on_pb_rechercherbouzid_clicked();

    void on_pb_trinombouzid_clicked();

    void on_pb_imprimerbouzid_clicked();

    void on_pb_typebouzid_clicked();

    void on_pb_quantitebouzid_clicked();

    void on_pb_prixbouzid_clicked();

    void on_pb_recherchernombouzid_clicked();

    void on_pb_recherchertypebouzid_clicked();

    void on_notifierpbbouzid_clicked();

    void on_PDFbouzid_clicked();

    void on_pb_Qrcodebouzid_clicked();



    void on_RB_ONbouzid_clicked();

    void on_RB_OFFbouzid_clicked();

    void on_pb_supprimer_clicked();

private:
    Ui::MainWindow *ui;
    Produit Pro;
    QCompleter* Model_Completer;
      QCompleter* Model_Completer1;
       QCompleter* Model_Completer2;
       QSystemTrayIcon *mSystemTrayIcon;
       Arduino A;
};


#endif // MAINWINDOW_H
