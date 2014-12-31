#ifndef DAGMW_H
#define DAGMW_H

#include <QMainWindow>

namespace Ui {
class dagmw;
}

class dagmw : public QMainWindow
{
    Q_OBJECT

public:
    explicit dagmw(QWidget *parent = 0);
    ~dagmw();

private:
    Ui::dagmw *ui;
private slots:
    void creerPersonne();
    void creerArbre();
};

#endif // DAGMW_H
