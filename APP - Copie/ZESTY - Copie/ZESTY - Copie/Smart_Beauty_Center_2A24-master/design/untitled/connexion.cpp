#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnexion(){
        db=QSqlDatabase::addDatabase("QODBC");
            db.setDatabaseName("sourceprojet_2A");
            db.setUserName("mariem");
            db.setPassword("1111");
            return db.open();

}

void connexion::closeconnexion(){

    db.close();
}
