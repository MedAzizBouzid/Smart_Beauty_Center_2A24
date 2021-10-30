#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QApplication>
class Employe
{
public:
    Employe();
    Employe(int, int, int, QString, QString, QString, QString);
    int getCIN();
    int getTelephone();
    int getH_Travail();
    QString getNom();
    QString getPrenom();
    QString getAdresse();
    QString getRole();
    void setCIN(int);
    void setTelephone(int);
    void setH_Travail(int);
    void setNom(QString);
    void setPrenom(QString);
    void setAdresse(QString);
    void setRole(QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();


private:
    int CIN,Telephone,H_Travail;
    QString Nom, Prenom,Adresse,Role;

};

#endif // EMPLOYE_H
