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
{ QSqlQuery query;
QString resCAB=QString::number(cab);
    query.prepare(" Delete from produits where Code_ABar=:cab");
    query.bindValue(":cab", resCAB);

    return query.exec();
}

bool Produit::modifier(int cab)
{

QSqlQuery query;
QString res_cab= QString::number(cab);
 bool test =query.exec() ;
query.prepare("Update produit set  CODE_ABAR=:code_abar,NOM=:nom, TYPE_P=:type ,QUANTITE=:quantite,PRIX=:prix  where CODE_ABAR =:code_abar ");
query.bindValue(":code_abar",res_cab);
query.bindValue(":nom",NomProduit);
query.bindValue(":type_p",Type);
query.bindValue(":quantite",Quantite);
query.bindValue(":prix",Prix);


   return test;
}
QSqlQueryModel* Produit::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM produits");

return model;
}
QSqlQueryModel*  Produit::rechercher_cab(int cab)
 { QString res_cab=QString::number(cab);

    QSqlQuery qry;


     qry.prepare("select * from produit where Code_ABar=:cab");
     qry.bindValue(":cab",res_cab);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(qry);




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
