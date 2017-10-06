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
    serial = new QSerialPort(this);
    settings = new SettingsDialog;

    status = new QLabel;
    ui->statusBar->addWidget(status);
    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);
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
        myData[0] = 145;
        writeData(myData);
    } else {
        showStatusMessage(tr("Band 1 clicked: data sent;  0 001 0 001 = 17 decimal"));
        myData[0] = 17;
        writeData(myData);
    }
    ui->pushButton->setChecked(true);
    ui->pushButton_1->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_7->setChecked(false);
}

void MainWindow::on_pushButton_1_clicked()
{
    if(ui->pushButton_mox->isChecked()) {
        showStatusMessage(tr("Band 2 clicked: data sent;  1 010 0 010 = 162 decimal"));
        myData[0] = 162;
        writeData(myData);
    } else {
        showStatusMessage(tr("Band 2 clicked: data sent;  0 010 0 010 = 34 decimal"));
        myData[0] = 34;
        writeData(myData);
    }
    ui->pushButton->setChecked(false);
    ui->pushButton_1->setChecked(true);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_7->setChecked(false);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_mox->isChecked()) {
        showStatusMessage(tr("Band 3 clicked: data sent;  1 011 0 011 = 179 decimal"));
        myData[0] = 179;
        writeData(myData);
    } else {
        showStatusMessage(tr("Band 3 clicked: data sent;  0 011 0 011 = 51 decimal"));
        myData[0] = 51;
        writeData(myData);
    }
    ui->pushButton->setChecked(false);
    ui->pushButton_1->setChecked(false);
    ui->pushButton_2->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_7->setChecked(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_mox->isChecked()) {
        showStatusMessage(tr("Band 4 clicked: data sent;  1 100 0 100 = 196 decimal"));
        myData[0] = 196;
        writeData(myData);
    } else {
        showStatusMessage(tr("Band 4 clicked: data sent;  0 100 0 100 = 68 decimal"));
        myData[0] = 51;
        writeData(myData);
    }
    ui->pushButton->setChecked(false);
    ui->pushButton_1->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(true);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_7->setChecked(false);
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->pushButton_mox->isChecked()) {
        showStatusMessage(tr("Band 5 clicked: data sent;  1 101 0 101 = 213 decimal"));
        myData[0] = 213;
        writeData(myData);
    } else {
        showStatusMessage(tr("Band 5 clicked: data sent;  0 101 0 101 = 85 decimal"));
        myData[0] = 51;
        writeData(myData);
    }
    ui->pushButton->setChecked(false);
    ui->pushButton_1->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(true);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_7->setChecked(false);
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->pushButton_mox->isChecked()) {
        showStatusMessage(tr("Band 6 clicked: data sent;  1 110 0 110 = 150 decimal"));
        myData[0] = 150;
        writeData(myData);
    } else {
        showStatusMessage(tr("Band 6 clicked: data sent;  0 110 0 110 = 22 decimal"));
        myData[0] = 51;
        writeData(myData);
    }
    ui->pushButton->setChecked(false);
    ui->pushButton_1->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(true);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_7->setChecked(false);
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_mox->isChecked()) {
        showStatusMessage(tr("Band 7 clicked: data sent;  1 001 0 111 = 151 decimal"));
        myData[0] = 151;
        writeData(myData);
    } else {
        showStatusMessage(tr("Band 7 clicked: data sent;  0 001 0 111 = 23 decimal"));
        myData[0] = 51;
        writeData(myData);
    }
    ui->pushButton->setChecked(false);
    ui->pushButton_1->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(true);
    ui->pushButton_7->setChecked(false);
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->pushButton_mox->isChecked()) {
        showStatusMessage(tr("Band 7 clicked: data sent;  1 001 0 111 = 151 decimal"));
        myData[0] = 151;
        writeData(myData);
    } else {
        showStatusMessage(tr("Band 7 clicked: data sent;  0 001 0 111 = 23 decimal"));
        myData[0] = 51;
        writeData(myData);
    }
    ui->pushButton->setChecked(false);
    ui->pushButton_1->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_7->setChecked(true);
}

void MainWindow::on_pushButton_mox_clicked()
{
    if(ui->pushButton->isChecked()) {
        on_pushButton_clicked();
    } else if (ui->pushButton_2->isChecked()) {
        on_pushButton_2_clicked();
    } else if (ui->pushButton_3->isChecked()) {
        on_pushButton_3_clicked();
    } else if (ui->pushButton_4->isChecked()) {
        on_pushButton_4_clicked();
    } else if (ui->pushButton_5->isChecked()) {
        on_pushButton_5_clicked();
    } else if (ui->pushButton_6->isChecked()) {
        on_pushButton_6_clicked();
    } else if (ui->pushButton_7->isChecked()) {
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_actionConnect_triggered()
{
    openSerialPort();
}

void MainWindow::on_actionDisconnect_triggered()
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

void MainWindow::on_actionSettings_triggered()
{
    settings->show();
}

