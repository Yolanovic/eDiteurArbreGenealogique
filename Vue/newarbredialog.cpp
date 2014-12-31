#include "newarbredialog.h"
#include "ui_newarbredialog.h"
#include <QtSql>
#include <iostream>
#include <sstream>
using namespace std;
newArbreDialog::newArbreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newArbreDialog)
{
    ui->setupUi(this);
}
void newArbreDialog::accept(){
    stringstream ss;
    ss<<"INSERT INTO arbre (nomArbre, creation)VALUES ('";
    ss<<ui->nomArbre->text().toStdString()<<"',";
    ss<<" date('now'));";
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( QDir::homePath() + QDir::separator() + "dag.db3");
    db.open();
    QSqlQuery query(db);
    QString requete = QString::fromStdString(ss.str());
    if(query.exec(requete));
    else qDebug()<<query.lastError();
    this->close();
}

newArbreDialog::~newArbreDialog()
{
    delete ui;
}
