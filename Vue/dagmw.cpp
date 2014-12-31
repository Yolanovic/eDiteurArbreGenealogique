#include "dagmw.h"
#include "ui_dagmw.h"
#include "newpersondialog.h"
#include "newarbredialog.h"
#include <iostream>

dagmw::dagmw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dagmw)
{
    ui->setupUi(this);
    QObject::connect(ui->actionNouveau_noeud,SIGNAL(triggered()),SLOT(creerPersonne()));
    QObject::connect(ui->actionNouvel_arbre,SIGNAL(triggered()),SLOT(creerArbre()));
}
void dagmw::creerPersonne(){
    newPersonDialog * npd= new newPersonDialog(this);
    npd->setVisible(true);
}
void dagmw::creerArbre(){
    newArbreDialog * nad= new newArbreDialog(this);
    nad->setVisible(true);
}

dagmw::~dagmw()
{
    delete ui;
}
