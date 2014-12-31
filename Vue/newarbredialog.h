#ifndef NEWARBREDIALOG_H
#define NEWARBREDIALOG_H

#include <QDialog>

namespace Ui {
class newArbreDialog;
}

class newArbreDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newArbreDialog(QWidget *parent = 0);
    ~newArbreDialog();

private:
    Ui::newArbreDialog *ui;
    void accept();
};

#endif // NEWARBREDIALOG_H
