#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"produit.h"
#include<QValidator>
#include<QMessageBox>
#include<QComboBox>
#include<QSqlQuery>
#include <QRegExpValidator>
#define NOM_RX "^([a-z]+[A-Z]+[ ]?|[a-z]+[A-Z])+$"
#define NUM_RX "^([0-9]+[,.]?)+$"
      QRegExp rxNom(NOM_RX);
      QRegExp rxNum(NUM_RX);
      QRegExpValidator* valiNom= new QRegExpValidator(rxNom);
       QRegExpValidator* valiNum= new QRegExpValidator(rxNum);
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
    ui->background_5->setPixmap(pix);





    ui->le_nom->setValidator(valiNom);
    ui->le_nommodifier->setValidator(valiNom);
    ui->le_type->setValidator(valiNom);
    ui->le_typemodifier->setValidator(valiNom);
    ui->le_prix->setValidator(valiNum);
    ui->le_prixmodifier->setValidator(valiNum);
    ui->le_cab->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_cabsupp->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_quantite->setValidator(new QIntValidator(0, 999999, this));
    ui->le_cabsupp->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_quantitemodifier->setValidator(new QIntValidator(0, 999999, this));

    ui->tab_afficher->setModel(Pro.afficher());

             Model_Completer=new QCompleter(this);
             Model_Completer->setModel(Pro.wombo_comboNom());
             ui->le_nomrechercher->setCompleter(Model_Completer);
              Model_Completer2=new QCompleter(this);
             Model_Completer2->setModel(Pro.wombo_combo());
             ui->le_cabrechercher->setCompleter(Model_Completer2);


        ui->comboBox->setModel(Pro.wombo_combo());
        ui->comobox_supprimer->setModel(Pro.wombo_combo());

        Model_Completer1=new QCompleter(this);
        Model_Completer1->setModel(Pro.wombo_comboType());
        ui->le_typerechercher->setCompleter(Model_Completer1);
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


            bool test;
    int pos=P.Notifier();

    if(NomProduit=="" || Prix==0 || CodeABar==0 || Type=="" || Quantite==0 )
            test=false;
    else test=P.ajouter();
    if(test)
   {QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué avec succées \n Click cancel to exit. "),QMessageBox::Cancel);


        Model_Completer=new QCompleter(this);
        Model_Completer->setModel(Pro.wombo_comboNom());
        ui->le_nomrechercher->setCompleter(Model_Completer);


        Model_Completer1=new QCompleter(this);
        Model_Completer1->setModel(Pro.wombo_comboType());
        ui->le_typerechercher->setCompleter(Model_Completer1);
        ui->tab_afficher->setModel(P.afficher());


        if(pos==0)
QMessageBox::critical(nullptr,QObject::tr("Attention Stock"),QObject::tr("Stock est épuisé.\n Veuillez contacter le fournisseur \n Click cancel to exit."),QMessageBox::Cancel);

    else if(pos==1)
        QMessageBox::critical(nullptr,QObject::tr("Attention Stock"),QObject::tr("stock sera épuisé prochainement .\n Click cancel to exit."),QMessageBox::Cancel);

  }  else {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué.\n Click cancel to exit."),QMessageBox::Cancel);
ui->tab_afficher->setModel(P.afficher());}
}

void MainWindow::on_pb_supprimer_clicked()
{
    Produit P1;
    P1.setCodeABar(ui->comobox_supprimer->currentText().toInt());
    bool test=P1.supprimer(P1.GetCodeabar());

    if(test)
    {QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectué avec succées \n Click cancel to exit. "),QMessageBox::Cancel);

        Model_Completer=new QCompleter(this);
        Model_Completer->setModel(Pro.wombo_comboNom());
        ui->le_nomrechercher->setCompleter(Model_Completer);
        Model_Completer1=new QCompleter(this);
        Model_Completer1->setModel(Pro.wombo_comboType());
        ui->le_typerechercher->setCompleter(Model_Completer1);
        ui->tab_afficher->setModel(Pro.afficher());
        ui->comobox_supprimer->setModel(P1.wombo_combo());
}
    else QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Supppression non effectué.\n Click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pb_modifier_clicked()
{
QString NomProduitn=ui->le_nommodifier->text();
float Prixn=ui->le_quantitemodifier->text().toInt();
int cab=ui->comboBox->currentText().toInt();
//int cab=ui->le_cabmodifier->text().toInt();
QString Typen=ui->le_typemodifier->text();
int Quantiten=ui->le_prixmodifier->text().toFloat();

Produit P(NomProduitn,cab,Typen,Quantiten,Prixn);

bool test=P.modifier(cab);

if(NomProduitn=="" || Prixn==0 || cab==0 || Typen=="" || Quantiten==0 )
test=false;
if(test)
{

    ui->tab_afficher->setModel(Pro.afficher());
    ui->comboBox->setModel(P.wombo_combo());
    ui->comobox_supprimer->setModel(P.wombo_combo());
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(Pro.wombo_comboNom());
    ui->le_nomrechercher->setCompleter(Model_Completer);
    Model_Completer1=new QCompleter(this);
    Model_Completer1->setModel(Pro.wombo_comboType());
    ui->le_typerechercher->setCompleter(Model_Completer1);
    QMessageBox::information(nullptr,QObject::tr("Modifier produit"),QObject::tr("Modification effectué avec succées \n Click cancel to exit. "),QMessageBox::Cancel);
int pos=P.Notifier();
    if(pos==0)
        QMessageBox::critical(nullptr,QObject::tr("Attention Stock"),QObject::tr("Stock est épuisé.\n Veuillez contacter le fournisseur \n Click cancel to exit."),QMessageBox::Cancel);

            else if(pos==1)
                    QMessageBox::critical(nullptr,QObject::tr("Attention Stock"),QObject::tr("stock sera épuisé prochainement .\n Click cancel to exit."),QMessageBox::Cancel);
}
else {
    ui->tab_afficher->setModel(Pro.afficher());
    QMessageBox::critical(nullptr,QObject::tr("Modifier produit"),QObject::tr("Modification non effectué.\n Click cancel to exit."),QMessageBox::Cancel);
}

}


void MainWindow::on_pb_rechercher_clicked()
{

int cab=ui->le_cabrechercher->text().toInt();

Model_Completer=new QCompleter(this);
    Model_Completer->setModel(Pro.wombo_combo());
    ui->le_cabrechercher->setCompleter(Model_Completer);
      QSqlQueryModel* Model_Complete=Pro.rechercher_cab( cab);
      if (Model_Complete != nullptr)
                             {
                                 ui->tab_rechercher->setModel(Model_Complete);
                             }


}

void MainWindow::on_pb_recherchernom_clicked()
{
    QString nom=ui->le_nomrechercher->text();

    Model_Completer=new QCompleter(this);
        Model_Completer->setModel(Pro.wombo_comboNom());
        ui->le_nomrechercher->setCompleter(Model_Completer);
          QSqlQueryModel* Model_Complete=Pro.rechercher_nom( nom);
          if (Model_Complete != nullptr)
                                 {
                                     ui->tab_rechercher->setModel(Model_Complete);
                                 }

}
void MainWindow::on_pb_recherchertype_clicked()
{QString type=ui->le_typerechercher->text();

    Model_Completer=new QCompleter(this);
        Model_Completer->setModel(Pro.wombo_comboType());
        ui->le_typerechercher->setCompleter(Model_Completer);
          QSqlQueryModel* Model_Complete=Pro.rechercher_type( type);
          if (Model_Complete != nullptr)
                                 {
                                     ui->tab_rechercher->setModel(Model_Complete);
                                 }


}

void MainWindow::on_pb_trinom_clicked()
{
    QSqlQueryModel* model=Pro.trienom( );
    if(model !=nullptr)
         ui->tab_trie->setModel(model);
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQueryModel* model=Pro.trietype( );
    if(model !=nullptr)
         ui->tab_trie->setModel(model);
}

void MainWindow::on_pb_type_clicked()
{
    QSqlQueryModel* model=Pro.trietype( );
    if(model !=nullptr)
         ui->tab_trie->setModel(model);
}

void MainWindow::on_pb_quantite_clicked()
{
    QSqlQueryModel* model=Pro.triequantite( );
    if(model !=nullptr)
         ui->tab_trie->setModel(model);
}

void MainWindow::on_pb_prix_clicked()
{
    QSqlQueryModel* model=Pro.trieprix( );
    if(model !=nullptr)
         ui->tab_trie->setModel(model);
}



