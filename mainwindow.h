#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"produit.h"
#include <QDirModel>
#include <QCompleter>
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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_trinom_clicked();

    void on_pushButton_clicked();

    void on_pb_type_clicked();

    void on_pb_quantite_clicked();

    void on_pb_prix_clicked();

    void on_pb_recherchernom_clicked();

    void on_pb_recherchertype_clicked();

private:
    Ui::MainWindow *ui;
    Produit Pro;
    QCompleter* Model_Completer;
      QCompleter* Model_Completer1;
       QCompleter* Model_Completer2;
};


#endif // MAINWINDOW_H
