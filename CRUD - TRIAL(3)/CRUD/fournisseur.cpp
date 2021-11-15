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
QSqlQueryModel* fournisseur::wombo_combo_type(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select Type_P from fournisseurs");
    return model;
}
QSqlQueryModel* fournisseur::wombo_combo_local(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select Localisation from fournisseurs");
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
bool fournisseur::modifier_code(QString id){
    QSqlQuery query;


    query.prepare("Update fournisseurs set Code_F = :Code_F where Code_F = :id ");
    query.bindValue(":id", id);
    query.bindValue(":Code_F",Code_F);

    return query.exec();
}
bool fournisseur::modifier_num(QString id){
    QSqlQuery query;

    QString p_string=QString::number(Prix);

    query.prepare("Update fournisseurs set Num_tel = :Num_tel where Code_F = :id ");
    query.bindValue(":id", id);

    query.bindValue(":Num_tel",Num_tel);

    return query.exec();
}
bool fournisseur::modifier_type(QString id){
    QSqlQuery query;

    QString p_string=QString::number(Prix);

    query.prepare("Update fournisseurs set Type_P = :Type_P where Code_F = :id ");
    query.bindValue(":id", id);

    query.bindValue(":Type_P",Type_P);
    return query.exec();
}
bool fournisseur::modifier_local(QString id){
    QSqlQuery query;

    QString p_string=QString::number(Prix);

    query.prepare("Update fournisseurs set Localisation = :Localisation where Code_F = :id ");
    query.bindValue(":id", id);
    query.bindValue(":Localisation",Localisation);
    return query.exec();
}
bool fournisseur::modifier_prix(QString id){
    QSqlQuery query;

    QString p_string=QString::number(Prix);

    query.prepare("Update fournisseurs set Prix = :Prix  where Code_F = :id ");
    query.bindValue(":id", id);

    query.bindValue(":Prix", p_string);

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
QSqlQueryModel* fournisseur::cherhcer_local(QString local){

        QSqlQuery qry;


         qry.prepare("SELECT * FROM fournisseurs where Localisation=:local");
         qry.bindValue(":local",local);
         qry.exec();
         QSqlQueryModel *model= new QSqlQueryModel;
         model->setQuery(qry);

        return model;
  }
QSqlQueryModel* fournisseur::cherhcer_type(QString type){

        QSqlQuery qry;


         qry.prepare("SELECT * FROM fournisseurs where Type_P=:type");
         qry.bindValue(":type",type);
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
