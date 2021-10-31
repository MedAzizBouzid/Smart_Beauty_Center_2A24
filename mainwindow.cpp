#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"produit.h"
#include<QValidator>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/BERGILA/Desktop/2A24/projet/background.png");
    ui->background->setPixmap(pix);
    ui->background_2->setPixmap(pix);
    ui->background_3->setPixmap(pix);
    ui->background_4->setPixmap(pix);

    ui->le_cab->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_afficher->setModel(P.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString NomProduit=ui->le_nom->text();
    float Prix=ui->le_prix->text().toFloat();
int CodeABar=ui->le_cab->text().toInt();
QString Type=ui->le_type->text();
        int Quantite=ui->le_quantite->text().toInt();

    Produit P(  NomProduit,CodeABar,Type ,Prix, Quantite);

    bool test=P.ajouter();
    if(test)
    {QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué avec succées \n Click cancel to exit. "),QMessageBox::Cancel);
        ui->tab_afficher->setModel(P.afficher());

}else QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué.\n Click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_clicked()
{
    Produit P1;
    P1.setCodeABar(ui->le_cabsupp->text().toInt());
    bool test=P1.supprimer(P1.GetCodeabar());
    if(test)
    {QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectué avec succées \n Click cancel to exit. "),QMessageBox::Cancel);
ui->tab_afficher->setModel(P.afficher());
}
    else QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Supppression non effectué.\n Click cancel to exit."),QMessageBox::Cancel);
}
