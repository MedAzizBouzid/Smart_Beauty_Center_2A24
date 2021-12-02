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
bool Employe::ajouter()
{
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
           return query.exec();
    }
bool Employe::modifier(int CIN)
{
QSqlQuery query;
QString id_string=QString::number(CIN);
QString Telephone_string=QString::number(Telephone);
query.prepare("update employe set CIN = :cin , NUM_TEL = :num_tel , NOM = :nom , PRENOM = :prenom , ADRESSE = :adresse , ROLE = :role where CIN = :cin ");
query.bindValue(":cin", id_string);
query.bindValue(":num_tel", Telephone_string);
query.bindValue(":nom", Nom);
query.bindValue(":prenom", Prenom);
query.bindValue(":adresse", Adresse);
query.bindValue(":role", Role);
return    query.exec();
}
bool Employe::supprimer(int CIN)
{
    QSqlQuery query;
    QString res=QString::number(CIN);
    query.prepare("delete from employe where CIN= :cin");
    query.bindValue(":cin",res);

 return query.exec();

}
QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Role"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_Tel"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    return model;
}
QSqlQueryModel*  Employe::rechercher_Role(QString rrole)
 {
    QSqlQuery qry;
     qry.prepare("SELECT * FROM Employe where Role=:role");
     qry.bindValue(":role",rrole);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);

    return model;
 }
QSqlQueryModel*  Employe::rechercher_Prenom(QString pprenom)
 {

    QSqlQuery qry;
     qry.prepare("SELECT * FROM Employe where Prenom=:prenom");
     qry.bindValue(":prenom",pprenom);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);

    return model;
 }
QSqlQueryModel*  Employe::rechercher_nom(QString nnom)
 {
    QSqlQuery qry;
     qry.prepare("SELECT * FROM Employe where Nom=:nom");
     qry.bindValue(":nom",nnom);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);

    return model;
 }
QSqlQueryModel * Employe::Tri_role()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from Employe order by ROLE" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Role"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_Tel"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));

 return model;

}
QSqlQueryModel * Employe::Tri_prenom()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from Employe order by PRENOM" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Role"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_Tel"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));

 return model;

}
QSqlQueryModel * Employe::Tri_nom()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from Employe order by NOM" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Role"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_Tel"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));

 return model;

}
QSqlQueryModel* Employe::wombo_combo2(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select CIN from EMPLOYE");

    return model;
}
