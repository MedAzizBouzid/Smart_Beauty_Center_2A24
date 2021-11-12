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
    ui->TVTRI->setModel(Ctmp.tridate_rdv());//Tri
    QPixmap pix("C:/Users/Asus-PC/Desktop/background.png");
    ui->backgroundajouter_2->setPixmap(pix);
        ui->backgroundaffich->setPixmap(pix);
        ui->backgroundmodiff->setPixmap(pix);
                ui->backgroundrech->setPixmap(pix);
                 ui->bcksms->setPixmap(pix);
 ui->backgroundrdv->setPixmap(pix);
    ui->comboBox->addItem("cheveux");
     ui->comboBox->addItem("soin");
      ui->comboBox->addItem("makeup");
       ui->comboBox->addItem("ongles");
       ui->comboBox_2->addItem("cheveux");
        ui->comboBox_2->addItem("soin");
        ui->comboBox_2->addItem("makeup");
        ui->comboBox_2->addItem("ongles");
         ui->comboBox_srech->addItem("-");
        ui->comboBox_srech->addItem("cheveux");
         ui->comboBox_srech->addItem("soin");
          ui->comboBox_srech->addItem("makeup");
           ui->comboBox_srech->addItem("ongles");

         ui->comboBox_modif->setModel(Ctmp.rechav());
         ui->comboBox_Supp->setModel(Ctmp.rechav());
        ui->backgroundsupprimer->setPixmap(pix);
        ui->TABCLI->setModel(Ctmp.afficher());
        Model_Completer=new QCompleter(this);
            Model_Completer->setModel(Ctmp.rechav());
            ui->coderech->setCompleter(Model_Completer);
             ui->codesms->setCompleter(Model_Completer);
        ui->lenom->setValidator(valiNom);

        ui->leprenom->setValidator(valiNom);
        ui->lecode->setValidator(new QIntValidator(0, 9999, this));
        ui->lenum->setValidator(new QIntValidator(0, 99999999, this) );
        ui->ladresse->setValidator( new QRegExpValidator( QRegExp( "[a-z0-9_]{1,99}\\S@[a-z]{1,99}\\S\\.[a-z]{1,99}\\S+" ), this ) );
        ui->ladate->setValidator( new QRegExpValidator( QRegExp( "[0-31_]\\S/[0-12_]\\S\\/[0-2021_]\\S+" ), this ) );

        ui->nommodif->setValidator(valiNom);
        ui->prenommodif->setValidator(valiNom);

        ui->numtelmodif->setValidator( new QIntValidator(0, 99999999, this)  );
        ui->adressemodif->setValidator( new QRegExpValidator( QRegExp( "[a-z0-9_]{1,99}\\S@[a-z]{1,99}\\S\\.[a-z]{1,99}\\S+" ), this ) );
        ui->datemodif->setValidator( new QRegExpValidator( QRegExp( "[0-31_]\\S/[0-12_]\\S\\/[0-2021_]\\S+" ), this ) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbajouter_clicked()
{
    //recuperer les infos saisies dans les champs
    int code_C=ui->lecode->text().toInt();
    QString Num_tel=ui->lenum->text();
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
      Model_Completer=new QCompleter(this);
          Model_Completer->setModel(Ctmp.rechav());
          ui->coderech->setCompleter(Model_Completer);
  QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Ajout effectué\n Click Cancel to exit."), QMessageBox::Cancel);
}
else // si cvpas QMessageBox::critical
    QMessageBox::critical(nullptr, QObject::tr("not OK"), QObject::tr("Echec d'ajout\n Click Cancel to exit."));


}

void MainWindow::on_pb_supp_clicked()
{

    int ccd=ui->comboBox_modif->currentText().toInt();
 bool test=Ctmp.supprimer(ccd);
 if(test)
 {
           ui->TABCLI->setModel(Ctmp.afficher());
           ui->comboBox_Supp->setModel(Ctmp.rechav());
          Model_Completer=new QCompleter(this);
              Model_Completer->setModel(Ctmp.rechav());
              ui->coderech->setCompleter(Model_Completer);
     QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("Suppression effectué\n Click Cancel to exit."), QMessageBox::Cancel);
   }
   else // si cvpas QMessageBox::critical
       QMessageBox::critical(nullptr, QObject::tr("not OK"), QObject::tr("Echec de suppression\n Click Cancel to exit."));


}


void MainWindow::on_pbmodifier_clicked()
{
    int ccd=ui->comboBox_modif->currentText().toInt();
    QString Num_tel=ui->numtelmodif->text();
    QString Nom=ui->nommodif->text();
    QString Prenom=ui->prenommodif->text();
    QString Adresse_Mail=ui->adressemodif->text();
    QString Date_RDV=ui->datemodif->text();
   QString S_Attribue=ui->comboBox_2->currentText();
    Client C(ccd,Num_tel,Nom,Prenom,Adresse_Mail,Date_RDV,S_Attribue);
  bool test=C.modifier(ccd);
  if(test) // si cv QMessageBox::information
{

      ui->TABCLI->setModel(Ctmp.afficher());
       ui->comboBox_modif->setModel(Ctmp.rechav());
      Model_Completer=new QCompleter(this);
          Model_Completer->setModel(Ctmp.rechav());
          ui->coderech->setCompleter(Model_Completer);





  QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Modification effectué\n Click Cancel to exit."), QMessageBox::Cancel);
}
else // si cvpas QMessageBox::critical
    QMessageBox::critical(nullptr, QObject::tr("not OK"), QObject::tr("Echec de modification\n Click Cancel to exit."));


}



void MainWindow::on_pbrechercher_clicked()
{
    int code_C=ui->coderech->text().toInt();
    QString Date_RDV=ui->daterech->text();
    QString S_Attribue=ui->comboBox_srech->currentText();
          QSqlQueryModel* model=Ctmp.rechercher(code_C);
          QSqlQueryModel* model1=Ctmp.rechercherDate(Date_RDV);
          QSqlQueryModel* model2=Ctmp.rechercherService(S_Attribue);
          if (model != nullptr && code_C!=0 && Date_RDV=="" && S_Attribue=="-")
                                 {

                                     ui->tabrech->setModel(model);
                                 }
          else if (model1 != nullptr && code_C==0 && Date_RDV!="" && S_Attribue=="-")
                                   ui->tabrech->setModel(model1);
          else if (model1 != nullptr && code_C==0 && Date_RDV=="" && S_Attribue!="-")
                  ui->tabrech->setModel(model2);
}



void MainWindow::on_codesms_returnPressed()
{
    int code_C=ui->codesms->text().toInt();

          QSqlQueryModel* model=Ctmp.rechercher(code_C);
          if (model != nullptr)
                                 {

                                     ui->tabVsms->setModel(model);
                                 }
}


void MainWindow::on_pbsms_clicked()
{

on_codesms_returnPressed();
//QModelIndex index = ui->tabVsms->model()->index(index.row(),1); //affichage du num fi messagebox
    if(ui->radioButton->isChecked())
    {  QMessageBox::information(0, tr("type de SMS"),tr("SMS fidelité envoyé au client %1").arg(ui->codesms->text()));

    }
    if(ui->radioButton_2->isChecked())
    {
        QMessageBox::information(0, tr("type de SMS"),tr("SMS offres envoyé au client %1").arg(ui->codesms->text()));

    }

}





