#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"service.h"
#include<QTextEdit>
#include<QtCharts>
#include<QChartView>
#include<QPrinter>
#include<QPrintDialog>
#include <QTime>
#include<QSqlQuery>

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

    void on_groupBox_5_clicked();

    void on_search_pb_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pb_print2_clicked();

    void on_pushButton_2_clicked();

    void on_table_search_activated(const QModelIndex &index);

    void on_promo_pb_clicked();

    void on_pb_stat_clicked();

private:
    Ui::MainWindow *ui;
    Service S;
 QCompleter* Model_Completer;
 QSqlQuery qry;
};
#endif // MAINWINDOW_H
