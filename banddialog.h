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

signals:
    void sendBandData(int band, int value);
private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::bandDialog *ui;
    void writeSettings();
    void readSettings();
    void close();
    void reject();
    QList<QCheckBox *> l_checkboxes;
    QList<QCheckBox *> r_checkboxes;
};

#endif // BANDDIALOG_H
