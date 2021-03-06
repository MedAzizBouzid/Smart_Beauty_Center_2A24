#include "client.h"
#include <QSqlQuery>
#include <QtDebug>


Client::Client()
{
code_C =0 ;
Num_tel=" ";
Nom=" ";
Prenom=" ";
 Adresse_Mail=" "  ;
Date_RDV=" ";
S_Attribue=" ";
}


Client::Client( int code_C ,QString Num_tel , QString Nom, QString Prenom, QString Adresse_Mail, QString Date_RDV , QString S_Attribue)
{

this->code_C=code_C ;
this->Num_tel=Num_tel ;
this->Nom=Nom ;
this->Prenom=Prenom ;
this->Adresse_Mail=Adresse_Mail ;
this->Date_RDV=Date_RDV ;
this->S_Attribue=S_Attribue ;

}




bool Client::ajouter()
{

    QSqlQuery query;
    QString code_C_string= QString:: number(code_C);
         query.prepare("INSERT INTO CLIENT (CODE_C,NUM_TEL,NOM,PRENOM,ADRESSE_MAIL, DATE_RDV, S_ATTRIBUE) "
                       "VALUES (:code_c,:num_tel,:nom,:prenom,:adresse_mail, :date_rdv, :s_attribue)");
         query.bindValue(":code_c", code_C_string);
         query.bindValue(":num_tel", Num_tel);
         query.bindValue(":nom",Nom);
         query.bindValue(":prenom", Prenom);

         query.bindValue(":adresse_mail",Adresse_Mail );
         query.bindValue(":date_rdv",Date_RDV );
         query.bindValue(":s_attribue",S_Attribue );


        return query.exec()  ;

}

bool Client::supprimer(int code_C)
{
    QSqlQuery query;
    QString res=QString::number(code_C);
         query.prepare("Delete from CLIENT  where code_C=:code_C") ;
                      query.bindValue(":code_C",res);
                      return query.exec();

}


QSqlQueryModel * Client::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select * from CLIENT");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("code_C"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Num_tel"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prenom"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse_Mail"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date_RDV"));
              model->setHeaderData(6,Qt::Horizontal,QObject::tr("S_Attribue"));

    return model ;
}

bool Client::modifier(int code_C)
{
QSqlQuery query;
QString code_string=QString::number(code_C);
query.prepare("Update client set Code_C=:code_C  ,Num_tel= :num_tel , Nom= :nom , Prenom = :prenom , Adresse_Mail = :adresse_mail, Date_RDV =:date_rdv , S_Attribue= :s_attribue  where Code_C = :code_C ");
query.bindValue(":code_C", code_string);
query.bindValue(":num_tel", Num_tel );
query.bindValue(":nom", Nom);
query.bindValue(":prenom",Prenom);
query.bindValue(":adresse_mail", Adresse_Mail);
query.bindValue(":date_rdv",Date_RDV );
query.bindValue(":s_attribue",S_Attribue );
return   query.exec();
}


QSqlQueryModel*  Client::rechercher(int code_C)
 { QString code_string=QString::number(code_C);

    QSqlQuery qry;


     qry.prepare("SELECT* FROM client where Code_C=:code_C");
     qry.bindValue(":code_C",code_string);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);

    return model;

 }

QSqlQueryModel*  Client::recherchermail(QString Adresse_Mail)
 {

    QSqlQuery qry;


     qry.prepare("SELECT* FROM client where Adresse_Mail=:Adresse_Mail");
     qry.bindValue(":Adresse_Mail",Adresse_Mail);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);

    return model;

 }

QSqlQueryModel*  Client::rechercherDate(QString date)
 {

    QSqlQuery qry;


     qry.prepare("SELECT* FROM client where Date_RDV=:date");
     qry.bindValue(":date",date);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);

    return model;

 }

QSqlQueryModel*  Client::rechercherService(QString service)
 {

    QSqlQuery qry;


     qry.prepare("SELECT* FROM client where S_Attribue=:service");
     qry.bindValue(":service",service);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);

    return model;

 }


QSqlQueryModel* Client::rechav(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select Code_C from client");
    return model;
}

QSqlQueryModel* Client::rechavmail(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select Adresse_Mail from client");
    return model;
}

QSqlQueryModel * Client::tridate_rdv(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from client order by Date_RDV ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code_C"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("Num_tel"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prenom"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse_Mail"));
              model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date_RDV"));
                model->setHeaderData(6,Qt::Horizontal,QObject::tr("S_Attribue"));

    return model;
}
