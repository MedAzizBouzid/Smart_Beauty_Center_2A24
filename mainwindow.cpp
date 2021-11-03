#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"produit.h"
#include<QValidator>
#include<QMessageBox>
#include<QSqlQuery>
#include <QRegExpValidator>
#define NOM_RX "^([a-z]+[ ]?|[a-z])+$"
      QRegExp rxNom(NOM_RX);
      QRegExpValidator* valiNom= new QRegExpValidator(rxNom);
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




ui->le_nom->setValidator(valiNom);
ui->le_nommodifier->setValidator(valiNom);
ui->le_type->setValidator(valiNom);
ui->le_typemodifier->setValidator(valiNom);


    ui->le_cab->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_cabsupp->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_quantite->setValidator(new QIntValidator(0, 999999, this));
    ui->le_prix->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_cabmodifier->setValidator(new QIntValidator(0, 999999969, this));
    ui->le_cabsupp->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_quantitemodifier->setValidator(new QIntValidator(0, 999999, this));
    ui->le_prixmodifier->setValidator(new QIntValidator(0, 9999999, this));
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
    int pos=P.Notifier();
    if(NomProduit=="" || Prix==0 || CodeABar==0 || Type=="" || Quantite==0 )
            test=false;
    if(test)
   {QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué avec succées \n Click cancel to exit. "),QMessageBox::Cancel);
        ui->tab_afficher->setModel(P.afficher());
        if(pos==0)
QMessageBox::critical(nullptr,QObject::tr("Attention Stock"),QObject::tr("Stock est épuisé.\n Veuillez contacter le fournisseur \n Click cancel to exit."),QMessageBox::Cancel);

    else if(pos==1)
        QMessageBox::critical(nullptr,QObject::tr("Attention Stock"),QObject::tr("stock sera épuisé prochainement .\n Click cancel to exit."),QMessageBox::Cancel);

  }  else {QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué.\n Click cancel to exit."),QMessageBox::Cancel);
ui->tab_afficher->setModel(P.afficher());}
}

void MainWindow::on_pb_supprimer_clicked()
{
    Produit P1;
    P1.setCodeABar(ui->le_cabsupp->text().toLongLong());
    bool test=P1.supprimer(P1.GetCodeabar());
    if(P1.GetCodeabar()==0)
        test =false;
    if(test)
    {QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectué avec succées \n Click cancel to exit. "),QMessageBox::Cancel);
ui->tab_afficher->setModel(P.afficher());
}
    else QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Supppression non effectué.\n Click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pb_modifier_clicked()
{
    QString NomProduit=ui->le_nommodifier->text();
    float Prix=ui->le_prixmodifier->text().toFloat();
int CodeABar=ui->le_cabmodifier->text().toInt();
QString Type=ui->le_typemodifier->text();
        int Quantite=ui->le_quantitemodifier->text().toInt();

Produit P(NomProduit,CodeABar,Type,Quantite,Prix);

    bool test=P.modifier(CodeABar);
    int pos=P.Notifier();
    if(NomProduit=="" || Prix==0 || CodeABar==0 || Type=="" || Quantite==0 )
            test=false;
    if(test)
    {QMessageBox::information(nullptr,QObject::tr("Modifier produit"),QObject::tr("Modification effectué avec succées \n Click cancel to exit. "),QMessageBox::Cancel);
        ui->tab_afficher->setModel(P.afficher());
        if(pos==0)
QMessageBox::critical(nullptr,QObject::tr("Attention Stock"),QObject::tr("Stock est épuisé.\n Veuillez contacter le fournisseur \n Click cancel to exit."),QMessageBox::Cancel);

    else if(pos==1)
        QMessageBox::critical(nullptr,QObject::tr("Attention Stock"),QObject::tr("stock sera épuisé prochainement .\n Click cancel to exit."),QMessageBox::Cancel);
}
    else {QMessageBox::critical(nullptr,QObject::tr("Modifier produit"),QObject::tr("Modification non effectué.\n Click cancel to exit."),QMessageBox::Cancel);
ui->tab_afficher->setModel(P.afficher());}

}

void MainWindow::on_pb_rechercher_clicked()
{

int cab=ui->le_cabrechercher->text().toInt();

      QSqlQueryModel* model=P.rechercher_cab( cab);
      if (model!=nullptr)
                             {
                                 ui->table_rechercher->setModel(model);
                             }


}

