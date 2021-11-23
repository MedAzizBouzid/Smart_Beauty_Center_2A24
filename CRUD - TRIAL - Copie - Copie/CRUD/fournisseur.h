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
    bool modifier_code(QString);
    bool modifier_num(QString);
    bool modifier_type(QString);
    bool modifier_local(QString);
    bool modifier_prix(QString);
    QSqlQueryModel* afficher();
    QSqlQueryModel* wombo_combo();
    QSqlQueryModel* wombo_combo_type();
    QSqlQueryModel* wombo_combo_local();
    //Metiers
    QSqlQueryModel* cherhcer(QString);
    QSqlQueryModel* cherhcer_type(QString);
    QSqlQueryModel* cherhcer_local(QString);
    QSqlQueryModel* tri(QString);






    //Atrributes
    QString Code_F,Num_tel,Localisation,Type_P;
    float Prix;


};

#endif // FOURNISSEUR_H
