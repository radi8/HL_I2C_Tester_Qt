#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status = new QLabel;
//    status = new QLabel;
    ui->statusBar->addWidget(status);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}

void MainWindow::on_actionsetBands_triggered()
{

}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton_mox->isChecked()) {
        showStatusMessage(tr("Band 1 clicked: data sent;  1 001 0 001 = 145 decimal"));
/*
        myData[0] = 145;
        writeData(myData);
*/
    } else {
        showStatusMessage(tr("Band 1 clicked: data sent;  0 001 0 001 = 17 decimal"));
/*
        myData[0] = 17;
        writeData(myData);
*/
    }
    ui->pushButton->setChecked(true);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_7->setChecked(false);
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()
{

}

void MainWindow::on_pushButton_6_clicked()
{

}

void MainWindow::on_pushButton_7_clicked()
{

}

void MainWindow::on_pushButton_8_clicked()
{

}

void MainWindow::on_pushButton_mox_clicked()
{

}
