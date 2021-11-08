#ifndef PRODUIT_H
#define PRODUIT_H

#include<QString>
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QCompleter>
class Produit
{
public:
    Produit();
    Produit(QString,int ,QString,float,int);
    QString GetnomProduit();
    float GetPrix();
    int GetQuantite();
    QString GetType();
   int GetCodeabar();
    void setNomProduit(QString);
    void setPrix(float);
    void setQuantite(int);
    void setType(QString);
    void setCodeABar(int);
    bool ajouter ();
    QSqlQueryModel* afficher();
    bool supprimer(int  );
    bool modifier(int);
    QSqlQueryModel* rechercher_cab(int);
    QSqlQueryModel* rechercher_nom(QString nom);
    QSqlQueryModel* rechercher_type(QString type);
    void chat();
  int  Notifier();
  QSqlQueryModel* trienom();
  QSqlQueryModel* trietype();
  QSqlQueryModel* triequantite();
  QSqlQueryModel* trieprix();
  QSqlQueryModel* wombo_combo();
QSqlQueryModel* wombo_comboNom();
QSqlQueryModel* wombo_comboType();
private:
QString  NomProduit;
float Prix;
int Quantite;
int CodeABar;
QString Type;

};

#endif // PRODUIT_H
