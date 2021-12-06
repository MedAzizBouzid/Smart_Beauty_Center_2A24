#include "dialog.h"
#include "ui_dialog.h"
#include "employe.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QVideoWidget>
#include<windows.h>
#include <iostream>
using namespace std;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    e=false;
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    int cin=ui->lineEdit->text().toInt();
    QSqlQueryModel *m=empymp.rechercher_cin(cin);
    int s=0;
    s=m->data(m->index(0, 0)).toInt();
    if(s!=0)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Login avec succes.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
        e=true;
        this->hide();
       }


        else
        {
  QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Login échoue.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
  e=false;
        }

}

void Dialog::on_pushButton_2_clicked()
{
    this->hide();
    e=false;
    QMediaPlayer* player1 = new QMediaPlayer ;
    QVideoWidget* vw1 = new QVideoWidget ;
    player1->setVideoOutput(vw1);
    player1->setMedia(QUrl::fromLocalFile("C:\\Users\\Asus-PC\\Downloads\\APP - Copie\\APP - Copie\\ZESTY - Copie\\ZESTY - Copie\\Smart_Beauty_Center_2A24-master\\design\\pubSB.mp4"));
    vw1->showFullScreen();
    player1->play();
    Sleep(20000);
    player1->stop();
    vw1->close();
    vw1->deleteLater();
    this->show();
}
