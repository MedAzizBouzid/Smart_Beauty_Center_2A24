#ifndef DEPENSE_H
#define DEPENSE_H
#include <QString>
#include <QSqlQueryModel>

class Depense
{
public:
    Depense();
    Depense(float,QString,QString,int);



    float getsomme();

    QString getcategorie();
    QString getdescription();

    float R;


    void setsomme(float);

    void setcategorie(QString);
    void setdescription(QString);




    bool ajouter();
    bool remise(int code);
    bool supprimer(int);
    QSqlQueryModel*  afficher();

    bool modifier(int);

private:

    float somme;
    int code;
    QString categorie,description;
};

#endif // DEPENSE_H
