#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include <QMainWindow>

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
    void on_B_Ajout_clicked();

    void on_B_delete_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_B_Modifier_clicked();

    void on_pushButton_clicked();

    void on_Tri_nom_clicked();

private:
    Ui::MainWindow *ui;
    Employe Etmp;
};

#endif // MAINWINDOW_H
