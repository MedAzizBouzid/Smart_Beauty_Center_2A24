#include "employe.h"
#include <QtDebug>
Employe::Employe()
{
    CIN=0;   Telephone=0  ;  H_Travail=0;
     Nom="";  Prenom="";Adresse="" ;  Role="";
}


Employe::Employe(int CIN,int Telephone,int H_Travail,QString Nom,QString Prenom,QString Adresse,QString Role)
{this->CIN=CIN; this->Telephone=Telephone; this->H_Travail=H_Travail; this->Nom=Nom; this->Prenom=Prenom; this->Adresse=Adresse; this->Role=Role;}
int Employe::getCIN(){return CIN;}
int Employe::getTelephone(){return Telephone;}
int Employe::getH_Travail(){return H_Travail;}
QString Employe::getNom(){return Nom;}
QString Employe::getPrenom(){return Prenom;}
QString Employe::getAdresse(){return Adresse;}
QString Employe::getRole(){return Role;}
void Employe::setCIN(int CIN){this->CIN=CIN;}
void Employe::setTelephone(int Telephone){this->Telephone=Telephone;}
void Employe::setH_Travail(int H_Travail){this->H_Travail=H_Travail;}
void Employe::setNom(QString Nom){this->Nom=Nom;}
void Employe::setPrenom(QString Prenom){this->Prenom=Prenom;}
void Employe::setAdresse(QString Adresse){this->Adresse=Adresse;}
void Employe::setRole(QString Role){this->Role=Role;}
bool Employe::delete(int CIN)
{
    bool test=false;
    QSqlQuery query;
    QString res=QString::number(CIN);
        query.prepare("delete from employe where CIN= :cin");
        query.bindValue(":cin",res);
    return query.exec();
}
bool Employe::ajouter()
{bool test=false;
    QSqlQuery query;
    QString id_string=QString::number(CIN);
    QString Telephone_string=QString::number(Telephone);
          query.prepare("INSERT INTO EMPLOYE (CIN, NUM_TEL, NOM, PRENOM, ADRESSE, ROLE) "
                        "VALUES (:cin, :num_tel, :nom, :prenom, :adresse, :role)");
          query.bindValue(":cin" , id_string);
          query.bindValue(":num_tel", Telephone_string);
          query.bindValue(":nom", Nom);
          query.bindValue(":prenom", Prenom);
          query.bindValue(":adresse", Adresse);
          query.bindValue(":role", Role);
          query.exec();
    return test;}
