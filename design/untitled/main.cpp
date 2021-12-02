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
    Dialog d;
    bool test=c.createconnexion();
    MainWindow w;
    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                 QObject::tr("Connection successful.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("Connection failed.\n""Click Cancel to exit."),QMessageBox::Cancel);

    d.setModal(true);
    d.exec();
    w.show();
    return a.exec();
}
