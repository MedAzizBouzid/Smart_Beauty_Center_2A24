#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("ajout effectué\n"
                            "click cancel to exit."), QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                 QObject::tr("ajout non effectué\n"
                            "click cancel to exit."), QMessageBox::Cancel);

}
