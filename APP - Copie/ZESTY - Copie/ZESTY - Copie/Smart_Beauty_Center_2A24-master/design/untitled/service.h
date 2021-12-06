#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include<QSqlQueryModel>
#include <QTime>

class Service
{
public:
    Service();
    Service(int,QString,QString,float);

    void  time(QString);
    bool ajoutertime();


    int getcode_s();
    QString gettype_s();
    QString getdescriptions();
    float getprix();
    void setcode_s(int);
    void settype_s(QString);
    void setdescriptions(QString);
    void setprix(float);

    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel*  rechercher(int);
    bool supprimer(int);
    bool modifier(int);
    bool promo(int);

    QSqlQueryModel* wombo_comboType();
    QSqlQueryModel*  wombo_combocode();

    QSqlQueryModel* womboprix(int);
    private:

    int code_s;
    QString type_s,descriptions;
    float prix;
   QString times;
};

#endif // SERVICE_H
