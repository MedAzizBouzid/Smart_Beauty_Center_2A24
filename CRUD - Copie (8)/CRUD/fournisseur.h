#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>

class fournisseur
{
public:
    fournisseur();
    fournisseur(QString,QString,QString,QString,float);
    ~fournisseur();

    //CRUD
    bool ajouter();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel* afficher();
    QSqlQueryModel* wombo_combo();
    //Metiers
    QSqlQueryModel* cherhcer(QString);
    QSqlQueryModel* tri(QString);






    //Atrributes
    QString Code_F,Num_tel,Localisation,Type_P;
    float Prix;


};

#endif // FOURNISSEUR_H
