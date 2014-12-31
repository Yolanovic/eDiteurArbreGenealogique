#include "dagmw.h"
#include <QtSql/QtSql>
#include <QApplication>
#include "newpersondialog.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dagmw w;
    w.show();

    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE","first");
    db.setDatabaseName( QDir::homePath() + QDir::separator() + "dag.db3");

    if (db.open()) {
        QSqlQuery query(db);
        QString table = "personne";
        if (! (db.tables().contains(table ))) {
            std::cout<<"personne n'existe pas"<<std::endl;
            QString requete = "CREATE TABLE personne ( idpers INTEGER PRIMARY KEY, titre VARCHAR(5), nom VARCHAR(30), prenom VARCHAR(30), dateNaissance DATE, idPere INTEGER CHECK (idPere != idMere),idMere INTEGER  CHECK (idMere != idPere), marie BOOL, decede BOOL,	FOREIGN KEY (idPere) REFERENCES idpers, FOREIGN KEY (idMere) REFERENCES idmere); ";
            if (query.exec(requete));
            else qDebug()<<query.lastError();
        }
        table = "mariage";
        if (! (db.tables().contains(table ))) {
            std::cout<<"mariage n'existe pas"<<std::endl;
            QString requete = "CREATE TABLE mariage (idMari INTEGER, idFemme INTEGER, date DATE, PRIMARY KEY (idMari,idFemme,date), FOREIGN KEY(idMari) REFERENCES idpers, FOREIGN KEY (idFemme) REFERENCES idpers ); ";
            if (query.exec(requete));
            else qDebug()<<query.lastError();
        }
        table = "arbre";
        if (! (db.tables().contains(table))) {
            std::cout<<"arbre n'existe pas"<<std::endl;
            QString requete = "CREATE TABLE arbre (arbreId INTEGER PRIMARY KEY, creation DATE, nomArbre VARCHAR(30) ); ";
            if (query.exec(requete));
            else qDebug()<<query.lastError();
        }
        table = "appartenance";
        if (! (db.tables().contains(table))) {
            std::cout<<"appartenance n'existe pas"<<std::endl;
            QString requete = "CREATE TABLE appartenance (personne INTEGER, arbre INTEGER, PRIMARY KEY (personne,arbre), FOREIGN KEY(personne) REFERENCES idpers, FOREIGN KEY (arbre) references idArbre ); ";
            if (query.exec(requete));
            else qDebug()<<query.lastError();
        }

    }

    return a.exec();
}
