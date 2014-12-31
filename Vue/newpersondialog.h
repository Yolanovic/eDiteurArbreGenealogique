#ifndef NEWPERSONDIALOG_H
#define NEWPERSONDIALOG_H

#include <QDialog>


namespace Ui {
class newPersonDialog;
}

class newPersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newPersonDialog(QWidget *parent = 0);
    void accept();
    ~newPersonDialog();

private:
    Ui::newPersonDialog *ui;
    std::vector <std::pair<unsigned, std::string> >arbres;
};

#endif // NEWPERSONDIALOG_H
