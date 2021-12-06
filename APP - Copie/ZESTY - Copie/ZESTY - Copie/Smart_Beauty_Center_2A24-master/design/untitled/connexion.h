#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class connexion
{
    QSqlDatabase db;
public:
    connexion();
    bool createconnexion();
    void closeconnexion();

};

#endif // CONNEXION_H
