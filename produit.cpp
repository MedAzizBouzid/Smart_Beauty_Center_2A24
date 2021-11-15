#include "produit.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include<QSqlError>
#include<QMessageBox>
Produit::Produit()
{
NomProduit=" ";
Prix=0;
Quantite=0;
CodeABar=0;
Type=" ";


}
Produit::Produit(QString NomProduit,int cab,QString type ,float Prix,int Quantite)
{
    this->NomProduit=NomProduit;
    this->Prix=Prix;
    this->Quantite=Quantite;
    CodeABar=cab;
    Type=type;

}


QString Produit :: GetnomProduit()
{
    return NomProduit;
}
float Produit::GetPrix()
{
    return Prix;
}
int Produit::GetQuantite()
{
    return Quantite;
}
QString Produit::GetType()
{
    return Type;
}
int Produit::GetCodeabar()
{
    return CodeABar;
}
void Produit::setNomProduit(QString NomProduit)
{
    this->NomProduit=NomProduit;
}
void Produit::setPrix(float Prix)
{
    this->Prix=Prix;
}
void Produit::setQuantite(int Quantite)
{
    this->Quantite=Quantite;
}
void Produit:: setType(QString type)
{
    Type=type;
}
void Produit :: setCodeABar(int  cab)
{
 CodeABar=cab;
}















//crud
        bool Produit::ajouter()
        {

        bool test=true;
            QSqlQuery query;
            QString Quantite_string=QString::number(Quantite);
            QString Prix_string=QString::number(Prix);
            QString CAB_string=QString::number(CodeABar);



                 query.prepare("INSERT INTO PRODUITS (CODE_ABAR,NOM, TYPE_P ,QUANTITE,PRIX) "
                               "VALUES (:code_abar,:nom,:type_p,:quantite,:prix)");
                 query.bindValue(":code_abar",CAB_string );
                 query.bindValue(":nom", NomProduit);
                 query.bindValue(":type_p" ,Type );
                 query.bindValue(":quantite", Quantite_string);
                 query.bindValue(":prix", Prix_string);
                 query.exec();
                 return test;




        }

        bool Produit::supprimer(int  cab)
        {
            QSqlQuery query;
        QString resCAB=QString::number(cab);
            query.prepare(" Delete from produits where Code_ABar=:cab");
            query.bindValue(":cab", resCAB);
         return query.exec();


        }

        bool Produit::modifier(int cab)
        {

        QSqlQuery query;
        QString res_cab= QString::number(cab);
        QString Code_ABar_string=QString::number(CodeABar);
        QString Quantite_string=QString::number(Quantite);
        QString Prix_string=QString::number(Prix);

        query.prepare("UPDATE PRODUITS SET  Code_abar=:code_abar,Nom =:nom, Type_P=:type_p ,Quantite=:quantite,Prix=:prix  where Code_abar=:code_abar");


        query.bindValue(":code_abar",res_cab);
        query.bindValue(":nom",NomProduit);
        query.bindValue(":type_p",Type);
        query.bindValue(":quantite",Quantite_string);
        query.bindValue(":prix",Prix_string);

           return query.exec();
        }

        QSqlQueryModel* Produit::afficher()
        {
            QSqlQueryModel* model=new QSqlQueryModel();
            model->setQuery("SELECT* FROM produits");

        return model;
        }








int Produit::Notifier()
{int pos=3;

    if((Quantite<5)&&(Quantite>0))
    pos= 1;
else if(Quantite==0)
pos= 0;
    return pos;
}












//tri
QSqlQueryModel *Produit:: trienom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from produits order by NOM" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE_ABAR"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_P"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

 return model;
}
QSqlQueryModel *Produit:: trietype()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from produits order by TYPE_P" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE_ABAR"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_P"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

 return model;
}
QSqlQueryModel *Produit:: triequantite()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from produits order by Quantite" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE_ABAR"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_P"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

 return model;
}
QSqlQueryModel *Produit:: trieprix()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from produits order by PRIX" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE_ABAR"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_P"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

 return model;
}















//recherche avancee
QSqlQueryModel* Produit::wombo_combo(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select Code_ABar from Produits");
    return model;
}
QSqlQueryModel* Produit::wombo_comboNom(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select Nom from Produits");
    return model;
}
QSqlQueryModel* Produit::wombo_comboType(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select TYPE_P from Produits");
    return model;
}
QSqlQueryModel*  Produit::rechercher_cab(int cab)
 { QString res_cab=QString::number(cab);

    QSqlQuery qry;


     qry.prepare("SELECT* FROM produits where Code_abar=:cab");
     qry.bindValue(":cab",res_cab);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);


    return model;



 }
QSqlQueryModel*  Produit::rechercher_nom(QString nom)
 {

    QSqlQuery qry;


     qry.prepare("SELECT* FROM produits where Nom=:nom");
     qry.bindValue(":nom",nom);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);


    return model;



 }
QSqlQueryModel*  Produit::rechercher_type(QString type)
 {

    QSqlQuery qry;


     qry.prepare("SELECT* FROM produits where  TYPE_P =:type");
     qry.bindValue(":type",type);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery(qry);


    return model;



 }
