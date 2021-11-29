#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QComboBox>
#include "smtp.h"
#include <QCalendarWidget>
#include <QDateEdit>
#include <QDate>


#define NOM_RX "^([a-z]+[ ]?|[a-z])+$"
      QRegExp rxNom(NOM_RX);
      QRegExpValidator* valiNom= new QRegExpValidator(rxNom);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    ui->TVTRI->setModel(Ctmp.tridate_rdv());//Tri

    QString Adresse_Mail=ui->codemail->text();
    QSqlQueryModel* model=Ctmp.recherchermail(Adresse_Mail);
   ui->tvmail->setModel(model);

 //  QString Date=ui->calendarWidget->selectedDate().toString();
   //    QSqlQueryModel* modelm=Ctmp.rechercherDate(Date);
  // ui->tvrdv->setModel(modelm);

    QPixmap pix("C:/Users/Asus-PC/Desktop/background.png");
    ui->backgroundajouter_2->setPixmap(pix);
        ui->backgroundaffich->setPixmap(pix);
        ui->backgroundmodiff->setPixmap(pix);
                ui->backgroundrech->setPixmap(pix);
                 ui->bcksms->setPixmap(pix);
 ui->backgroundsupprimer->setPixmap(pix);
 ui->backgroundrdv->setPixmap(pix);
 QPixmap bf("C:/Users/Asus-PC/Desktop/bf.png");
 ui->brochfront->setPixmap(bf);
 QPixmap bb("C:/Users/Asus-PC/Desktop/bb.png");
 ui->brochback->setPixmap(bb);


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

        ui->TABCLI->setModel(Ctmp.afficher());
        Model_Completer=new QCompleter(this);
            Model_Completer->setModel(Ctmp.rechav());
            ui->coderech->setCompleter(Model_Completer);
             ui->codemail->setCompleter(Model_Completer);
             Model_Completer=new QCompleter(this);
                 Model_Completer->setModel(Ctmp.rechavmail());
                 ui->codemail->setCompleter(Model_Completer);

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
        ui->coderech->setValidator(new QIntValidator(0, 9999, this));
        ui->daterech->setValidator( new QRegExpValidator( QRegExp( "[0-31_]\\S/[0-12_]\\S\\/[0-2021_]\\S+" ), this ) );
        ui->codemail->setValidator( new QRegExpValidator( QRegExp( "[a-z0-9_]{1,99}\\S@[a-z]{1,99}\\S\\.[a-z]{1,99}\\S+" ), this ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbajoutermariem_clicked()
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
      ui->TVTRI->setModel(Ctmp.tridate_rdv());//Tri

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

void MainWindow::on_pb_suppmariem_clicked()
{

    int ccd=ui->comboBox_modif->currentText().toInt();
 bool test=Ctmp.supprimer(ccd);
 if(test)
 {
     ui->TVTRI->setModel(Ctmp.tridate_rdv());//Tri

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


void MainWindow::on_pbmodifiermariem_clicked()
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
      ui->TVTRI->setModel(Ctmp.tridate_rdv());//Tri
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



void MainWindow::on_pbrecherchermariem_clicked()
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



void MainWindow::on_codemailmariem_returnPressed()
{
    QString Adresse_Mail=ui->codemail->text();

          QSqlQueryModel* model=Ctmp.recherchermail(Adresse_Mail);
          if (model != nullptr)
                                 {

                                     ui->tvmail->setModel(model);
                                 }
}


void MainWindow::sendMail()
{
    Smtp *smtp= new Smtp("mariem52bel@gmail.com","Azertyuiop","smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
     if(ui->radioButton->isChecked())
     {
         smtp->sendMail("",ui->codemail->text(),"Mail fidélité","Félicitation cher client!\nGrace à votre fidélité vous bénificiez d'un service gratuit.\n Contactez nous pour en savoir plus.\n");
      }
     else if(ui->radioButton_2->isChecked())
     {
         smtp->sendMail("",ui->codemail->text(),"Offres","Annonce Offres !\nProfitez de nos offres jusqu'à -50% solde!\n Contactez nous pour en savoir plus.\n");
        }
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_pb_mailmariem_clicked()
{

      Smtp *smtp= new Smtp("mariem52bel@gmail.com","Azertyuiop","smtp.gmail.com");
      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
       if(ui->radioButton->isChecked())
       {
           smtp->sendMail("",ui->codemail->text(),"Mail fidélité","Félicitation cher client!\nGrace à votre fidélité vous bénificiez d'un service gratuit.\n Contactez nous pour en savoir plus.\n");
        }
       else if(ui->radioButton_2->isChecked())
       {
           smtp->sendMail("",ui->codemail->text(),"Offres","Annonce Offres !\nProfitez de nos offres jusqu'à -50% solde!\n Contactez nous pour en savoir plus.\n");
          }
     void mailSent(QString)  ;

}

void MainWindow::on_calendarWidgetmariem_clicked(const QDate &Date_RDV)
{

    ui->currentdate = new QDateEdit;
        ui->currentdate->setDisplayFormat("dd/MM/yyyy");
        ui->currentdate->setDate(Date_RDV);
        QString Date(ui->currentdate->text());
   //QString Date=ui->currentdate->toString();
    QSqlQueryModel* model=Ctmp.rechercherDate(Date);
    if (model != nullptr)
    {
       ui->tvrdv->setModel(model);
    }

}
