#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"service.h"

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

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_Valide_Modif_clicked();

private:
    Ui::MainWindow *ui;
    Service S;
};
#endif // MAINWINDOW_H
