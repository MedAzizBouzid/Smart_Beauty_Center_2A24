#include "connection.h"



Connection::Connection()
{
}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("sourceprojet_2A");
db.setUserName("Mariem");
db.setPassword("1111");

if (db.open())
test=true;


    return  test;
}

void Connection:: closeconnect(){db.close();}
