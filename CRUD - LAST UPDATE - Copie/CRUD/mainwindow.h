#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include <QMainWindow>
#include <QCompleter>
#include <QDirModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_pushButton_7_clicked();

    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Valide_Modif_clicked();

    void on_Chercher_clicked();

    void on_Tri_clicked();

    void on_Chercher_type_clicked();

    void on_Chercher_local_clicked();
    void Refresh();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    fournisseur fou;
    QCompleter* Model_Completer;
};
#endif // MAINWINDOW_H
