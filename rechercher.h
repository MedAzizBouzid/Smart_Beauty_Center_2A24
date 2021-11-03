#ifndef RECHERCHER_H
#define RECHERCHER_H

#include <QDialog>
#include"produit.h"
#include "ui_mainwindow.h"
namespace Ui {
class rechercher;
}

class rechercher : public QDialog
{
    Q_OBJECT

public:
    explicit rechercher(QWidget *parent = nullptr);
    ~rechercher();


private:
    Ui::rechercher *ui;
    Ui::MainWindow *ui1;
       Produit P;
};

#endif // RECHERCHER_H
