#ifndef BANDDIALOG_H
#define BANDDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QCheckBox>

namespace Ui {
class bandDialog;
}

class bandDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bandDialog(QWidget *parent = 0);
    ~bandDialog();

private:
    Ui::bandDialog *ui;
    void writeSettings();
    void readSettings();
    QList<QCheckBox *> l_checkboxes;
    QList<QCheckBox *> r_checkboxes;
};

#endif // BANDDIALOG_H
