#include "connexion.h"

connexion::connexion()
{

}
    bool connexion::createconnexion(){
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Base_Commune");
    db.setUserName("aziz");
    db.setPassword("aziz");
    return db.open();

}

void connexion::closeconnexion(){

    db.close();
}
