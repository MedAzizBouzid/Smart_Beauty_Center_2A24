#include "produit.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
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
void Produit :: setCodeABar(int cab)
{
 CodeABar=cab;
}

bool Produit::ajouter()
{


    QSqlQuery query;
    QString Quantite_string=QString::number(Quantite);
    QString Prix_string=QString::number(Prix);


         query.prepare("INSERT INTO PRODUITS (CODE_ABAR,NOM, TYPE_P ,QUANTITE,PRIX) "
                       "VALUES (:code a bar,:nom,:type,:quantite,:prix)");
         query.bindValue("code a bar", 15648);
         query.bindValue("nom", "aziz");
         query.bindValue("type" ,"parfum" );
         query.bindValue("quantite", "15");
         query.bindValue("prix", "3.2");
         return query.exec();




}
QSqlQueryModel* Produit::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM produits");

return model;
}
bool Produit::supprimer(int cab)
{ QSqlQuery query;

    query.prepare(" Delete from produits where Code_ABar=:cab");
    query.bindValue(0, cab);

    return query.exec();
}
QSqlQueryModel *  Produit::rechercher_cab(int cab)
 {
     QSqlQuery qry;
     qry.prepare("select * from produit where cab=:cab");
     qry.bindValue(":cab",cab);
     qry.exec();

     QSqlQueryModel *model= new QSqlQueryModel;
     model->setQuery(qry);


    return model;


 }
