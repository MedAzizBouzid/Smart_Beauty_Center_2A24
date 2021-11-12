#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>

class Client
{

private:
   int code_C;
   QString Num_tel;
   QString Nom, Prenom,Adresse_Mail,Date_RDV ,S_Attribue;

public:

    //Constructeurs
    Client();
    Client(int,QString, QString, QString,QString,QString,QString);

    //Getters
    int getcode_C(){return code_C;}
    QString getNum_tel(){return Num_tel;}
    QString getNom(){return Nom;}
     QString getPrenom(){return Prenom;}
     QString getAdresse_Mail(){return Adresse_Mail;}
     QString getDate_RDV(){return Date_RDV;}
     QString getS_Attribue(){return S_Attribue;}

     //Setters
     void setcode_C(int code_C){this->code_C=code_C;}
     void setNum_tel(QString Num_tel){this->Num_tel=Num_tel;}
     void setNom(QString Nom){this->Nom=Nom;}
     void setPrenom(QString Prenom){this->Prenom=Prenom;}
     void setAdresse_Mail(QString Adresse_Mail){this->Adresse_Mail=Adresse_Mail;}
     void setDate_RDV(QString Date_RDV){this->Date_RDV=Date_RDV;}
     void setS_Attribue(QString S_Attribue){this->S_Attribue=S_Attribue;}

     //CRUD
     bool ajouter();
     QSqlQueryModel *afficher();
     bool supprimer(int);
     bool modifier(int);
     QSqlQueryModel* rechav();
     QSqlQueryModel *rechercher(int );
     QSqlQueryModel*rechercherDate(QString);
     QSqlQueryModel*rechercherService(QString);
     QSqlQueryModel *tridate_rdv();
     void statistique(QVector<double>, QVector<QString>);

};

#endif // CLIENT_H
