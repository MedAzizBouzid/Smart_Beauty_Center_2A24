#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"service.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->Acode_s->setValidator(new QIntValidator(100, 99999, this));
    ui->Aprix->setValidator(new QIntValidator(0, 99999, this));
    ui->lineEdit_modif->setValidator(new QIntValidator(100, 99999, this));
    ui->lineEdit_nv_prix->setValidator(new QIntValidator(0,9999999,this));
   ui->tab_service->setModel(S.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_pb_ajouter_clicked()
{
    int code_s=ui->Acode_s->text().toInt();
    QString descriptions=ui->Adescription_s->text();
    QString type_s=ui->Atype_s->text();
    float prix=ui->Aprix->text().toFloat();
  Service S(code_s,descriptions,type_s,prix);
  bool test=S.ajouter();
       if(test)
       {

           QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("ajout effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);
           ui->tab_service->setModel(S.afficher());
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("ajout non effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
  Service S1;
S1.setcode_s(ui->Scode_s->text().toInt());
bool test=S1.supprimer(S1.getcode_s());
if(test)
{

    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectué\n"
                       "click cancel to exit."), QMessageBox::Cancel);
    ui->tab_service->setModel(S.afficher());
}
else
    QMessageBox::critical(nullptr,QObject::tr("Not OK"),
            QObject::tr("suppression non effectué\n"
                       "click cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_Valide_Modif_clicked()
{


    int code_s=ui->lineEdit_modif->text().toInt();
    QString desc_nv=ui->ndescriptions->text();
    QString type_s=ui->type_nv->text();
    float prix_nv=ui->lineEdit_nv_prix->text().toFloat();
 Service S(code_s,desc_nv,type_s,prix_nv);




       bool test=S.modifier(code_s);
       if(test)
       {

           QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("modifier effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);
           ui->tab_service->setModel(S.afficher());
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("modifier non effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);









   }



