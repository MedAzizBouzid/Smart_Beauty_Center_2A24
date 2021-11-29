#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include <QMainWindow>
#include <QCompleter>
#include <QDirModel>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QTextStream>
#include <QPrintDialog>




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
    void on_B_AjoutEmploye_clicked();

    void on_B_deleteEmploye_clicked();

    void on_tableViewEmploye_activated(const QModelIndex &index);

    void on_B_ModifierEmploye_clicked();

    void on_pushButtonEmploye_clicked();

    void on_Tri_nomEmploye_clicked();

    void on_PDFEmploye_clicked();

private:
    Ui::MainWindow *ui;
    Employe Etmp;
    QCompleter* Model_Completer;
};

#endif // MAINWINDOW_H
