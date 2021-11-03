#include "rechercher.h"
#include"mainwindow.h"

#include "ui_rechercher.h"
#include"produit.h"
#include<QSqlQuery>
rechercher::rechercher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rechercher)
{
    ui->setupUi(this);
    int cab=ui1->le_cabrechercher->text().toInt();
    ui->tableView->setModel(P.rechercher_cab(cab));
}

rechercher::~rechercher()
{
    delete ui;
}
