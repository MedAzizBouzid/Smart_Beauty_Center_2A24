#include "connexion.h"

connexion::connexion()
{

}
    bool connexion::createconnexion(){
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("system");
    db.setPassword("AZIZchehata15951");
    return db.open();

}

void connexion::closeconnexion(){

    db.close();
}
