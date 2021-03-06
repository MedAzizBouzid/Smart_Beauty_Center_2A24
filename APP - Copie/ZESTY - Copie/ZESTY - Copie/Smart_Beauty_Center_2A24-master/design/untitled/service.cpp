#include "service.h"
#include <QSqlQuery>
#include<QDebug>
#include<QObject>
#include <QTime>

Service::Service()
{
code_s=0;type_s="";descriptions="";prix=0;
}

Service::Service(int code_s,QString type_s,QString descriptions,float prix)
{

    this->code_s=code_s;
    this->type_s=type_s;
    this->descriptions=descriptions;
    this->prix=prix;

}

void Service::time(QString times)
{

this->times=times;



}



bool Service::ajoutertime()
{
     QSqlQuery query;

      query.prepare("INSERT INTO DATES (times) "
                    "VALUES (:id)");
      query.bindValue(":id", times);

 return query.exec();
}

int Service::getcode_s(){return code_s;};
QString Service::gettype_s(){return type_s;};
QString Service::getdescriptions(){return descriptions;};
float Service::getprix(){return prix;};
void Service::setcode_s(int code_s){this->code_s=code_s;};
void Service::settype_s(QString type_s){this->type_s=type_s;};
void Service::setdescriptions(QString descriptions){this->descriptions=descriptions;};
void Service::setprix(float prix){this->prix=prix;};

bool Service::ajouter()
{


    QSqlQuery query;
    QString code_s_string=QString::number(code_s);
    QString prix_string=QString::number(prix);
    query.prepare("INSERT INTO service (CODE_S, DESCRIPTIONS,TYPE_S,PRIX) "
                  "VALUES (:id, :forename, :surname,:prix)");
    query.bindValue(":id", code_s_string);
    query.bindValue(":forename", type_s);
    query.bindValue(":surname", descriptions);
    query.bindValue(":prix",prix_string);
    return query.exec();


}

bool Service::supprimer(int code_s)
{
    QSqlQuery query;

QString code_s_string=QString::number(code_s);
    query.prepare(" Delete from service where CODE_S=:code_s");
    query.bindValue(":code_s", code_s_string);


    return query.exec();

}

QSqlQueryModel* Service::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM SERVICE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_S"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_S"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTIONS"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));

         return  model;
}

bool Service::modifier(int code_s)
{


    QSqlQuery query;
    QString code_s_string=QString::number(code_s);
    QString prix_string=QString::number(prix);
    query.prepare("update service set CODE_S=:id,TYPE_S=:forename ,DESCRIPTIONS=:surname,PRIX=:prix where code_s=:id");
    query.bindValue(":id", code_s_string);
    query.bindValue(":forename", type_s);
    query.bindValue(":surname", descriptions);
    query.bindValue(":prix",prix_string);

    return query.exec();


}

QSqlQueryModel* Service::rechercher(int code_s)
{

    QSqlQuery query;
    QSqlQueryModel *model= new QSqlQueryModel;
     query.prepare("SELECT * FROM SERVICE where CODE_S=:code_s");
     query.bindValue(":code_s",code_s);
     query.exec();

model->setQuery(query);

    return model;
}

QSqlQueryModel* Service::wombo_comboType(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select TYPE_S from SERVICE");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}

QSqlQueryModel* Service::wombo_combocode(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select CODE_S from SERVICE");
    return model;
}



