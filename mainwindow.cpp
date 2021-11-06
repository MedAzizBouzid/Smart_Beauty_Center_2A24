#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QComboBox>

#define NOM_RX "^([a-z]+[ ]?|[a-z])+$"
      QRegExp rxNom(NOM_RX);
      QRegExpValidator* valiNom= new QRegExpValidator(rxNom);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Asus-PC/Desktop/background.png");
    ui->backgroundajouter_2->setPixmap(pix);
    ui->comboBox->addItem("cheveux");
     ui->comboBox->addItem("soin");
      ui->comboBox->addItem("makeup");
       ui->comboBox->addItem("ongles");
       ui->comboBox_2->addItem("cheveux");
        ui->comboBox_2->addItem("soin");
        ui->comboBox_2->addItem("makeup");
        ui->comboBox_2->addItem("ongles");
        ui->backgroundsupprimer->setPixmap(pix);
        ui->TABCLI->setModel(Ctmp.afficher());
        ui->lenom->setValidator(valiNom);

        ui->lecode->setValidator(new QIntValidator(0, 99999999, this));
        ui->lenum->setValidator(new QIntValidator(0, 99999999, this));
        ui->lecodesupp->setValidator(new QIntValidator(0, 99999999, this));
        ui->nommodif->setValidator(valiNom);
        ui->prenommodif->setValidator(valiNom);
        ui->codemodif->setValidator(new QIntValidator(0, 99999999, this));
        ui->numtelmodif->setValidator(new QIntValidator(0, 99999999, this));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbajouter_clicked()
{
    //recuperer les infos saisies dans les champs
    int code_C=ui->lecode->text().toInt();
        int Num_tel=ui->lenum->text().toInt();
    QString Nom=ui->lenom->text();
    QString Prenom=ui->leprenom->text();
    QString Adresse_Mail=ui->ladresse->text();
    QString Date_RDV=ui->ladate->text();
    QString S_Attribue=ui->comboBox->currentText();
    Client C(code_C,Num_tel,Nom,Prenom,Adresse_Mail,Date_RDV,S_Attribue);
  bool test=C.ajouter();

  if(test) // si cv QMessageBox::information
{

      ui->TABCLI->setModel(Ctmp.afficher());
  QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Ajout effectué\n Click Cancel to exit."), QMessageBox::Cancel);
}
else // si cvpas QMessageBox::critical
    QMessageBox::critical(nullptr, QObject::tr("not OK"), QObject::tr("Echec d'ajout\n Click Cancel to exit."));


}

void MainWindow::on_pb_supp_clicked()
{
 int code_C=ui->lecodesupp->text().toLong();
 bool test=Ctmp.supprimer(code_C);
 if(test)
 {
           ui->TABCLI->setModel(Ctmp.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("Suppression effectué\n Click Cancel to exit."), QMessageBox::Cancel);
   }
   else // si cvpas QMessageBox::critical
       QMessageBox::critical(nullptr, QObject::tr("not OK"), QObject::tr("Echec de suppression\n Click Cancel to exit."));


}


void MainWindow::on_pbmodifier_clicked()
{

    int nvcode_C=ui->codemodif->text().toInt();
        int Num_tel=ui->numtelmodif->text().toInt();
    QString Nom=ui->nommodif->text();
    QString Prenom=ui->prenommodif->text();
    QString Adresse_Mail=ui->adressemodif->text();
    QString Date_RDV=ui->datemodif->text();
   QString S_Attribue=ui->comboBox_2->currentText();
    Client C(nvcode_C,Num_tel,Nom,Prenom,Adresse_Mail,Date_RDV,S_Attribue);
  bool test=C.modifier(nvcode_C);
  if(test) // si cv QMessageBox::information
{

      ui->TABCLI->setModel(Ctmp.afficher());
  QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Modification effectué\n Click Cancel to exit."), QMessageBox::Cancel);
}
else // si cvpas QMessageBox::critical
    QMessageBox::critical(nullptr, QObject::tr("not OK"), QObject::tr("Echec de modification\n Click Cancel to exit."));


}



void MainWindow::on_pbrechercher_clicked()
{
    int code_C=ui->coderech->text().toInt();

          QSqlQueryModel* model=Ctmp.rechercher(code_C);
          if (model != nullptr)
                                 {

                                     ui->tabrech->setModel(model);
                                 }

}



void MainWindow::on_codesms_returnPressed()
{
    int code_C=ui->coderech->text().toInt();

          QSqlQueryModel* model=Ctmp.rechercher(code_C);
          if (model != nullptr)
                                 {

                                     ui->tabVsms->setModel(model);
                                 }
}

void MainWindow::on_pbsms_clicked()
{

on_codesms_returnPressed();

    if(ui->radioButton->isChecked())
    {  QMessageBox::information(0, "type de SMS","SMS fidelité envoyé ");

    }
    if(ui->radioButton_2->isChecked())
    {  QMessageBox::information(0, "type de SMS","SMS offres envoyé");

    }

}


