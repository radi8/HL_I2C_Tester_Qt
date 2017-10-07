#include "banddialog.h"
#include "ui_banddialog.h"

bandDialog::bandDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bandDialog)
{
    ui->setupUi(this);
}

bandDialog::~bandDialog()
{
    delete ui;
}
