#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.createconnexion();
    MainWindow w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                 QObject::tr("Connection successful.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("Connection failed.\n""Click Cancel to exit."),QMessageBox::Cancel);

    return a.exec();
}
