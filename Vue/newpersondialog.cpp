#include "newpersondialog.h"
#include "ui_newpersondialog.h"
#include <sstream>
#include<iostream>
#include <QtSql>

using namespace std;
newPersonDialog::newPersonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newPersonDialog)
{
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( QDir::homePath() + QDir::separator() + "dag.db3");
    db.open();
    QSqlQuery query(db);
    ui->setupUi(this);
    int j;
    QString k;
    QSqlQuery get(db);
    cout<<"select * from personne "<<endl;
    if (get.exec("select * from arbre "));
    else qDebug()<<query.lastError();
    while (get.next()) {
        stringstream ss;
        QVariant id;
        id=get.value(0);
        j=id.toInt();
        id=get.value(2);
        k=id.toString();
        pair <int,string> p ;
        p.first=j;
        p.second=k.toStdString();
        ui->arbre->addItem(QString::fromStdString(p.second));
        arbres.push_back(p);
    }
}

newPersonDialog::~newPersonDialog()
{
    delete ui;
}
void newPersonDialog::accept(){
    stringstream ss;
    string nom,prenom, ddn;
    QString i,j,k,table;
    QSqlDatabase db;
    nom = ui->nom->text().toStdString();
    prenom = ui->prenom->text().toStdString();
    ddn = ui->dateNaissance->selectedDate().year()+ui->dateNaissance->selectedDate().month()+ui->dateNaissance->selectedDate().day();
    ss<<"INSERT INTO personne (titre, nom, prenom, dateNaissance) VALUES (";
    if (ui->M->isChecked())ss<<"'M',";
    if (ui->Mme->isChecked())ss<<"'Mme',";
    if (ui->Mlle->isChecked())ss<<"'Mlle',";
    ss<<"'"<<nom<<"',";
    ss<<"'"<<prenom<<"',";
    ss<<"'"<<ddn<<"'";
    ss<<");";
    cout<<ss.str()<<endl;
    db =  QSqlDatabase::addDatabase("QSQLITE","second");
    db.setDatabaseName( QDir::homePath() + QDir::separator() + "dag.db3");
    db.open();
    QSqlQuery query(db);
    table = "personne";
    if ((db.tables().contains(table ))) {
        QString requete = QString::fromStdString(ss.str());
        if(query.exec(requete));
        else qDebug()<<query.lastError();
    }
    /*if (query.exec("select idpers from personne where() "));
     *par ici faut chopper l'id générer par la bd pour l'ajouter a la table appartenance
     *
     */
    else qDebug()<<query.lastError();
    QSqlQuery get(db);
    while (get.next()) {
        QVariant id;
        id=get.value(0);
        i=id.toString();
        if (get.exec("select * from personne "));
        else qDebug()<<query.lastError();
        while (get.next()) {
            QVariant id;
            id=get.value(0);
            i=id.toString();
            id=get.value(2);
            j=id.toString();
            id=get.value(3);
            k=id.toString();
            cout<<i.toStdString()<<" "<<j.toStdString()<<" "<<k.toStdString()<<endl;

            this->close();


        }

    }
}
