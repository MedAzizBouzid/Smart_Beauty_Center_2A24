#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnexion(){
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Base_Commune");
    db.setUserName("oussema");
    db.setPassword("oussema");
    return db.open();

}

void connexion::closeconnexion(){

    db.close();
}
