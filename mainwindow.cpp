#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myData.resize(1); //Setup to transmit a single byte
//    serial = new QSerialPort(this);




    serial = new QSerialPort(this);
    settings = new SettingsDialog;

    status = new QLabel;
//    status = new QLabel;
    ui->statusBar->addWidget(status);
    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error), this, &MainWindow::handleError);
  //  connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
  //          this, &MainWindow::handleError);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
//    connect(console, &Console::getData, this, &MainWindow::writeData);
//    connect(ui->actionSettings, &QAction::triggered, settings, &SettingsDialog::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}
//    connect(ui->actionConfigure, &QAction::triggered, settings, &SettingsDialog::show);
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
//        console->setEnabled(true);
//        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
//        ui->actionConfigure->setEnabled(false);
        ui->actionSettings->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
//    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
//    ui->actionConfigure->setEnabled(true);
    ui->actionSettings->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}

void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}

void MainWindow::readData()
{
    QByteArray data = serial->readAll();
//    console->putData(data);
    ui->plainTextEdit->appendPlainText(data);
}


void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}

void MainWindow::on_actionsetBands_triggered()
{

}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
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

void MainWindow::on_actionConnect_triggered()
{

}

void MainWindow::on_actionDisconnect_triggered()
{

}

void MainWindow::on_actionSettings_triggered()
{

}
