#include "connection.h"


//test tutoriel Git
Connection::Connection()
{
}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("sourceprojet_2A");//inserer le nom de la source de données ODBC
db.setUserName("Mariem");//inserer nom de l'utilisateur
db.setPassword("1111");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
