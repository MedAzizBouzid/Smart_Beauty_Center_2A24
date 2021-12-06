#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "dialog.h"
#include "connexion.h"
#include "fournisseur.h"
#include "client.h"
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>
#include <QCoreApplication>
#include "chatserver.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include<windows.h>
#include<QSystemTrayIcon>

using namespace ApexAlliance;

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



//****************MARIEM*********************

    QTranslator t;
    QStringList languages;
    languages <<"French" << "English" ;
    QString lang = QInputDialog::getItem(NULL, "Select Language", "Language",languages);
    if ( lang == "English")
    {
        t.load(":/english.qm");
    }
    if (lang != "French")
    {
        a.installTranslator(&t);
    }









    connexion c;
    MainWindow w;
    Dialog d;
    bool test=c.createconnexion();
    ChatServer Server;
    if(!Server.startServer(3333)){
        qDebug()<<"Error:"<<Server.errorString();
        //return 1;

    }
    qDebug()<<"Server   started ...";
    if(test)
    {

        w.Get_notif()->showMessage(QObject::tr("Message"),QObject::tr("Connexion successful"));

    }else
        w.Get_notif()->showMessage(QObject::tr("Message"),QObject::tr("Connexion failed"));
        while(!d.Get_close())
        {
            d.setModal(true);
            d.exec();
        }
        d.close();
        d.deleteLater();
               /* QMediaPlayer* player1 = new QMediaPlayer ;
                QVideoWidget* vw1 = new QVideoWidget ;
                player1->setVideoOutput(vw1);
                player1->setMedia(QUrl::fromLocalFile("C:\\Users\\Asus-PC\\Downloads\\APP - Copie\\APP - Copie\\ZESTY - Copie\\ZESTY - Copie\\Smart_Beauty_Center_2A24-master\\design\\transition.mp4"));
                vw1->setGeometry(100,100,100,100);
                vw1->showFullScreen();
                player1->play();
                Sleep(5000);
                player1->stop();
                vw1->close(); */
                w.showFullScreen();

    return a.exec();
}
