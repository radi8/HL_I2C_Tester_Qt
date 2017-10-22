#include "banddialog.h"
#include "ui_banddialog.h"
#include "mainwindow.h"

#include <cmath>

#include <QDebug>

bandDialog::bandDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bandDialog)
{
    ui->setupUi(this);

    l_checkboxes = ui->frame->findChildren<QCheckBox *>(QString());
    r_checkboxes = ui->frame_3->findChildren<QCheckBox *>(QString());

    int cbLen = l_checkboxes.length();
    int a, b;
    bool swapped = true;

//    qDebug() << Q_FUNC_INFO << "l_checkboxes = " << cbLen;

    while (swapped) {
        swapped = false;
        for(int x = 0; x < (cbLen-1); x++) {
            a = ((l_checkboxes[x]->objectName()).mid(9)).toInt();
            b = ((l_checkboxes[x+1]->objectName()).mid(9)).toInt();
            if(b < a){
                l_checkboxes.swap(x,(x+1));
                swapped = true;
            }
        }
    }

    cbLen = r_checkboxes.length();
    swapped = true;
    while (swapped) {
        swapped = false;
        for(int x = 0; x < (cbLen-1); x++) {
            a = ((r_checkboxes[x]->objectName()).mid(10)).toInt();
            b = ((r_checkboxes[x+1]->objectName()).mid(10)).toInt();
            if(b < a){
                r_checkboxes.swap(x,(x+1));
                swapped = true;
            }
        }
    }

    readSettings();
}

bandDialog::~bandDialog()
{
    int bandNumber = 0;
    int lValue = 0;
    int rValue = 0;
    for(int x = 7; x < l_checkboxes.length(); x += 8) {
        lValue = 0;
        rValue = 0;
        for(int y = (x - 7); y <= x; y++) {
            if(l_checkboxes[y]->isChecked()) {
                lValue += pow(2, (x-y));
            }
            if(r_checkboxes[y]->isChecked()) {
                rValue += pow(2, (x-y));
            }
        }
        emit sendBandData(bandNumber, lValue);
        emit sendBandData(bandNumber, rValue);
        bandNumber++;
    }
    emit setBtnText(0, ui->lineEdit->text());
    emit setBtnText(1, ui->lineEdit_2->text());
    emit setBtnText(2, ui->lineEdit_3->text());
    emit setBtnText(3, ui->lineEdit_4->text());
    emit setBtnText(4, ui->lineEdit_5->text());
    emit setBtnText(5, ui->lineEdit_6->text());
    emit setBtnText(6, ui->lineEdit_7->text());
    emit setBtnText(7, ui->lineEdit_8->text());

    writeSettings();
    delete ui;
}


void bandDialog::writeSettings()
{
    QSettings settings("Hermes-Lite", "HL_I2C_Tester_Qt");


    settings.setValue("band0", ui->lineEdit->text());
    settings.setValue("band1", ui->lineEdit_2->text());
    settings.setValue("band2", ui->lineEdit_3->text());
    settings.setValue("band3", ui->lineEdit_4->text());
    settings.setValue("band4", ui->lineEdit_5->text());
    settings.setValue("band5", ui->lineEdit_6->text());
    settings.setValue("band6", ui->lineEdit_7->text());
    settings.setValue("band7", ui->lineEdit_8->text());

    //Transmit checkBoxes
    for(int x =0; x < l_checkboxes.length(); x++) {
        settings.setValue(l_checkboxes[x]->objectName(), l_checkboxes[x]->isChecked());
    }
    //Receive checkBoxes
    for(int x =0; x < r_checkboxes.length(); x++) {
        settings.setValue(r_checkboxes[x]->objectName(), r_checkboxes[x]->isChecked());
    }
}

void bandDialog::readSettings()
{
    QSettings settings("Hermes-Lite", "HL_I2C_Tester_Qt");

    ui->lineEdit->setText(settings.value("band0", "Band 0").toString());
    ui->lineEdit_2->setText(settings.value("band1", "Band 1").toString());
    ui->lineEdit_3->setText(settings.value("band2", "Band 2").toString());
    ui->lineEdit_4->setText(settings.value("band3", "Band 3").toString());
    ui->lineEdit_5->setText(settings.value("band4", "Band 4").toString());
    ui->lineEdit_6->setText(settings.value("band5", "Band 5").toString());
    ui->lineEdit_7->setText(settings.value("band6", "Band 6").toString());
    ui->lineEdit_8->setText(settings.value("band7", "Band 7").toString());
    ui->lineEditR->setText(settings.value("band0", "Band 0").toString());
    ui->lineEditR_2->setText(settings.value("band1", "Band 1").toString());
    ui->lineEditR_3->setText(settings.value("band2", "Band 2").toString());
    ui->lineEditR_4->setText(settings.value("band3", "Band 3").toString());
    ui->lineEditR_5->setText(settings.value("band4", "Band 4").toString());
    ui->lineEditR_6->setText(settings.value("band5", "Band 5").toString());
    ui->lineEditR_7->setText(settings.value("band6", "Band 6").toString());
    ui->lineEditR_8->setText(settings.value("band7", "Band 7").toString());

    //Transmit checkBoxes
    for(int x =0; x < l_checkboxes.length(); x++) {
        l_checkboxes[x]->setChecked(settings.value(l_checkboxes[x]->objectName(), false).toBool());
    }
    //Receive checkBoxes
    for(int x =0; x < r_checkboxes.length(); x++) {
        r_checkboxes[x]->setChecked(settings.value(r_checkboxes[x]->objectName(), false).toBool());
    }
}

void bandDialog::reject()
{
    qDebug() << "Band closed";
    QDialog::hide();
}


void bandDialog::on_pushButtonClose_clicked()
{
   done(0);
}
