#ifndef BANDDIALOG_H
#define BANDDIALOG_H

#include <QDialog>
#include <QSettings>

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
};

#endif // BANDDIALOG_H
