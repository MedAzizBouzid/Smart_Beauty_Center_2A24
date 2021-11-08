#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"
#define NOM_RX "^([a-z]+[ ]?|[a-z])+$"
      QRegExp rxNom(NOM_RX);
      QRegExpValidator* valiNom= new QRegExpValidator(rxNom);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_telephone->setValidator(new QIntValidator(0,99999999,this));
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->CIN_supp->setValidator(new QIntValidator(0,99999999,this));
    ui->tableView->setModel(Etmp.afficher());
    ui->comboBox->setModel(Etmp.wombo_combo());
    ui->comboBox_2->setModel(Etmp.wombo_combo());
    ui->le_nom->setValidator(valiNom);
    ui->le_role->setValidator(valiNom);
    ui->le_prenom->setValidator(valiNom);
    ui->Mod_Nom->setValidator(valiNom);
    ui->Mod_Role->setValidator(valiNom);
    ui->Mod_Prenom->setValidator(valiNom);


    QPixmap pix("C:/Users/LENOVO/Desktop/Gestion Employee/background.png");
        ui->background_1->setPixmap(pix);
        ui->background_2->setPixmap(pix);
        ui->background_3->setPixmap(pix);
        ui->background_4->setPixmap(pix);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_Ajout_clicked()
{
   int id=ui->le_id->text().toInt();
   int telephone=ui->le_telephone->text().toInt();
   int H_travail=0;
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   QString adresse=ui->le_adresse->text();
   QString role=ui->le_role->text();
Employe E(id,telephone,H_travail,nom,prenom,adresse,role);
     bool test=E.ajouter();
     if(test)
     {
         ui->tableView->setModel(Etmp.afficher());
         ui->comboBox->setModel(Etmp.wombo_combo());
         ui->comboBox_2->setModel(Etmp.wombo_combo());
         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("ajout effectué\n"
                            "click cancel to exit."), QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                 QObject::tr("ajout non effectué\n"
                            "click cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_B_delete_clicked()
{
   int id = ui->comboBox_2->currentText().toInt();
   bool test=Etmp.supprimer(id);
   if(test)
   {
       ui->tableView->setModel(Etmp.afficher());
       ui->comboBox->setModel(Etmp.wombo_combo());
       ui->comboBox_2->setModel(Etmp.wombo_combo());
       QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("suppression effectué\n"
                          "click cancel to exit."), QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr,QObject::tr("Not OK"),
               QObject::tr("suppression non effectué\n"
                          "click cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_B_Modifier_clicked()
{
    int id = ui->comboBox->currentText().toInt();
        QString nom= ui->Mod_Nom->text();
        QString prenom= ui->Mod_Prenom->text();
        QString role= ui->Mod_Role->text();
        QString adresse= ui->Mod_Adresse->text();
        int telephone= ui->Mod_Telephone->text().toInt();
Employe E(id,telephone,0,nom,prenom,adresse,role);
      bool test=E.modifier(id);
      if(test)
    {

           ui->tableView->setModel(Etmp.afficher());
           ui->comboBox->setModel(Etmp.wombo_combo());
           ui->comboBox_2->setModel(Etmp.wombo_combo());
    QMessageBox::information(nullptr, QObject::tr("modifier une agence"),
                      QObject::tr("Agence modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier une agence"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    QString nnom=ui->Recherche->text();

          QSqlQueryModel* model=Etmp.rechercher_nom(nnom);
          if (model != nullptr)
 {
          ui->tableView_2->setModel(model);
 }
}

void MainWindow::on_Tri_nom_clicked()
{
     QSqlQueryModel* model=Etmp.Tri_nom();
     ui->tableView_2->setModel(model);

}
