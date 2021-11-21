#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_trinom_clicked();

    void on_pb_imprimer_clicked();

    void on_pb_type_clicked();

    void on_pb_quantite_clicked();

    void on_pb_prix_clicked();

    void on_pb_recherchernom_clicked();

    void on_pb_recherchertype_clicked();

    void on_notifierpb_clicked();

    void on_PDF_clicked();

    void on_pb_Qrcode_clicked();



private:
    Ui::MainWindow *ui;
    Produit Pro;
    QCompleter* Model_Completer;
      QCompleter* Model_Completer1;
       QCompleter* Model_Completer2;
       QSystemTrayIcon *mSystemTrayIcon;
};


#endif // MAINWINDOW_H
