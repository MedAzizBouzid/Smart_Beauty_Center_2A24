#include "depense.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Depense::Depense()
{
   somme=0; categorie=""; description="";
}

Depense::Depense(float somme,QString categorie ,QString description,int code)
{this->somme=somme; this->categorie=categorie;this->description=description;this->code=code;}

float Depense::getsomme(){return somme;}

QString Depense::getdescription(){return description;}
QString Depense::getcategorie(){return categorie;}



void Depense::setsomme(float somme){this->somme=somme;}

void Depense::setcategorie(QString categorie){this->categorie=categorie;}
void Depense::setdescription(QString description){this->description=description;}


bool Depense::ajouter()
{

    QSqlQuery query;
    QString string_somme= QString::number(somme);
    QString string_code= QString::number(code);
    QString s="",s1="";
    query.prepare("insert into Comptabilite (Code_fact,Categorie,Somme,Descriptions) "
                  "VALUES ( :Code, :categorie, :somme, :descriptions)");
    query.bindValue(":somme", string_somme);
    query.bindValue(":categorie", categorie);
    query.bindValue(":descriptions", description);

    query.bindValue(":Code", string_code);

    return query.exec();


}

bool Depense::supprimer(int code)
{
    QSqlQuery query;




    query.prepare("Delete from COMPTABILITE where Code_fact= :code");
    query.bindValue(":code",code);

    return query.exec();
}

QSqlQueryModel* Depense::afficher()
{

         QSqlQueryModel* model = new QSqlQueryModel();
         model->setQuery("SELECT* FROM Comptabilite");





 return model;

}




bool Depense::modifier(int code)
{
QSqlQuery query;

QString string_somme= QString::number(somme);
QString string_code= QString::number(code);


query.prepare("Update COMPTABILITE set  categorie = :categorie  , somme = :somme , descriptions = :description  where Code_fact = :code ");
query.bindValue(":code", string_code);
query.bindValue(":categorie", categorie);
query.bindValue(":description", description);
query.bindValue(":somme", string_somme);

return    query.exec();
}


