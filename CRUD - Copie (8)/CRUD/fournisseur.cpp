#include "fournisseur.h"

fournisseur::fournisseur()
{

}
fournisseur::fournisseur(QString c,QString n,QString l,QString t,float p){
    Code_F=c;
    Num_tel=n;
    Localisation=l;
    Type_P=t;
    Prix=p;

}

fournisseur::~fournisseur()
{

}
QSqlQueryModel* fournisseur::wombo_combo(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select Code_F from fournisseurs");
    return model;
}
bool fournisseur::ajouter(){
    QSqlQuery q;
    QString res=QString::number(Prix);
    q.prepare("INSERT INTO fournisseurs (Code_F,Localisation,Num_tel,Type_P,Prix)""Values(:Code_F, :Localisation, :Num_tel, :Type_P, :Prix)");
    q.bindValue(":Code_F",Code_F);
    q.bindValue(":Num_tel",Num_tel);
    q.bindValue(":Localisation",Localisation);
    q.bindValue(":Type_P",Type_P);
    q.bindValue(":Prix",res);
    return q.exec();
}
bool fournisseur::supprimer(QString code){
    QSqlQuery q;
    q.prepare("delete from fournisseurs where Code_F= :code");
    q.bindValue(":code",code);
    return q.exec();
}
QSqlQueryModel* fournisseur::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from fournisseurs");

    return model;
}
bool fournisseur::modifier(QString id){
    QSqlQuery query;

    QString p_string=QString::number(Prix);

    query.prepare("Update fournisseurs set Code_F = :Code_F , Localisation = :Localisation , Type_P = :Type_P , Num_tel = :Num_tel , Prix = :Prix  where Code_F = :id ");
    query.bindValue(":id", id);
    query.bindValue(":Code_F",Code_F);
    query.bindValue(":Num_tel",Num_tel);
    query.bindValue(":Prix", p_string);
    query.bindValue(":Localisation",Localisation);
    query.bindValue(":Type_P",Type_P);
    return query.exec();
}
QSqlQueryModel* fournisseur::cherhcer(QString code){

        QSqlQuery qry;


         qry.prepare("SELECT* FROM fournisseurs where Code_F=:code");
         qry.bindValue(":code",code);
         qry.exec();
         QSqlQueryModel *model= new QSqlQueryModel;
         model->setQuery(qry);

        return model;
  }
QSqlQueryModel* fournisseur::tri(QString code){
            QSqlQuery qry;
             qry.prepare("select * from fournisseurs where Type_P= :code order by Prix");
             qry.bindValue(":code",code);
             qry.exec();
             QSqlQueryModel *model= new QSqlQueryModel;
             model->setQuery(qry);

            return model;
  }
